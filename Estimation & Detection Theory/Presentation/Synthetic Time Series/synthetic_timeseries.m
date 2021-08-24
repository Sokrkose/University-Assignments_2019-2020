%% clear memory, screen, and close all figures
clear, clc, close all;

%pkg load statistics;
%pkg load econometrics;

%% Process equation x[k] = sys(k, x[k-1], u[k]);
nx = 1;                                                               % number of states
phi1=0.5;
omega=0.04;
sys = @(k, xkm1, uk) 1+sin(omega*pi*k) + phi1*xkm1 + uk;              % (returns column vector)

%% Observation equation y[k] = obs(k, x[k], v[k]);
ny = 1;                                                              % number of observations
phi2=0.2;
phi3=0.5;

obs1 = @(k, xkm1, vk) (phi2*xkm1^2 + vk);                            % (returns column vector) t<=30
%obs2 = @(k, xkm1, vk) (phi3*xkm1 - 2 + vk);                          % (returns column vector) t>30

%% PDF of process noise and noise generator function
nu = 1;                                                               % size of the vector of process noise
sigma_u = sqrt(10);
p_sys_noise   = @(u) gampdf(u, 3, 2);
gen_sys_noise = @(u) gamrnd(3, 2);                                    % sample from p_sys_noise (returns column vector)

%% PDF of observation noise and noise generator function
nv = 1;                                                               % size of the vector of observation noise
sigma_v = 10;
p_obs_noise   = @(v) normpdf(v, 0, sigma_v);
gen_obs_noise = @(v) normrnd(0, sigma_v);                            % sample from p_obs_noise (returns column vector)

%% Initial PDF
gen_x0 = @(x) normrnd(0, sqrt(10));                                  % sample from p_x0 (returns column vector)

%% Number of time steps
T = 60;

%% Separate memory space
x = zeros(nx,T);  y = zeros(ny,T);
u = zeros(nu,T);  v = zeros(nv,T);

%% Transition prior PDF p(x[k] | x[k-1])
% (under the suposition of additive process noise)
p_xk_given_xkm1 = @(k, xk, xkm1) p_sys_noise(xk - sys(k, xkm1, 0));

%% Observation likelihood PDF p(y[k] | x[k])
% (under the suposition of additive process noise)
p_yk_given_xk1 = @(k, yk, xk) p_obs_noise(yk - obs1(k, xk, 0));
p_yk_given_xk2 = @(k, yk, xk) p_obs_noise(yk - obs2(k, xk, 0));

%% Simulate system
xh0 = 0;                                  % initial state
u(:,1) = 0;                               % initial process noise
v(:,1) = gen_obs_noise(sigma_v);          % initial observation noise
x(:,1) = xh0;

y(:,1) = obs1(1, xh0, v(:,1));
for k = 2:T
   % here we are basically sampling from p_xk_given_xkm1 and from p_yk_given_xk
   u(:,k) = gen_sys_noise();              % simulate process noise
   v(:,k) = gen_obs_noise();              % simulate observation noise
   x(:,k) = sys(k, x(:,k-1), u(:,k));     % simulate state
   y(:,k) = obs1(k, x(:,k),   v(:,k));    % simulate observation
end

%% Separate memory
xh = zeros(nx, T); 
xh(:,1) = xh0;
yh = zeros(ny, T); 
yh(:,1) = obs1(1, xh0, 0);
pf.k               = 1;                   % initial iteration number
pf.Ns              = 200;                 % number of particles
pf.w               = zeros(pf.Ns, T);     % weights
pf.particles       = zeros(nx, pf.Ns, T); % particles
pf.gen_x0          = gen_x0;              % function for sampling from initial pdf p_x0
pf.p_yk_given_xk   = p_yk_given_xk1;       % function of the observation likelihood PDF p(y[k] | x[k])
pf.gen_sys_noise   = gen_sys_noise;       % function for generating process noise

%% Estimate state
for k = 2:T
   
   fprintf('Iteration = %d/%d\n',k,T);
   
   %state estimation
   pf.k = k;
   
   %[xh(:,k), pf] = particle_filter(sys, y(:,k), pf, 'multinomial_resampling');
   [xh(:,k), pf] = particle_filter(sys, obs1, y(:,k), pf, 'residual_sampling'); 
 
   % filtered observation
   yh(:,k) = obs1(k, xh(:,k), 0);

end



% 
% 
% %Again for the next observation function...
% 
% for k = 31:T
%    % here we are basically sampling from p_xk_given_xkm1 and from p_yk_given_xk
%    u(:,k) = gen_sys_noise();              % simulate process noise
%    v(:,k) = gen_obs_noise();              % simulate observation noise
%    x(:,k) = sys(k, x(:,k-1), u(:,k));     % simulate state
%    y(:,k) = obs1(k, x(:,k),   v(:,k));    % simulate observation
% end
% 
% %% Estimate state
% for k = 31:T
%    fprintf('Iteration = %d/%d\n',k,T);
%    % state estimation
%    pf.k = k;
%    %[xh(:,k), pf] = particle_filter(sys, y(:,k), pf, 'multinomial_resampling');
%    [xh(:,k), pf] = particle_filter(sys, obs1, y(:,k), pf, 'residual_sampling'); 
%  
%    % filtered observation
%    yh(:,k) = obs1(k, xh(:,k), 0);
% end
% 
% 
% 




%% Calculates the Mean Error Estimation
errors = zeros(nx, T);
for index = 1:T
    errors(index) = xh(index) - x(index);
end
meanError = mean(errors);
meanError 

%% plot of the state vs estimated state by the particle filter vs particle paths
figure
hold on;
h1 = plot(1:T,squeeze(pf.particles),'k');
h2 = plot(1:T,x,'b','LineWidth',4);
h3 = plot(1:T,xh,'r','LineWidth',4);
legend([h2 h3 h1(1)],'state','mean of estimated state','particle paths');
title('State vs estimated state by the particle filter vs particle paths','FontSize',14);

%% plot of the observation vs filtered observation by the particle filter
figure
plot(1:T,y,'b', 1:T,yh,'r');
legend('observation','filtered observation');
title('Observation vs filtered observation by the particle filter','FontSize',14);

return;