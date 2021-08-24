function [xk, wk, idx] = resample(xk, wk, resampling_strategy)
Ns = length(wk);  % Ns = number of particles

switch resampling_strategy
   case 'residual_sampling' 
         idx  = resampleResidual(wk);
   otherwise
      error('Resampling strategy not implemented')
end;
xk = xk(:,idx);                    % extract new particles
wk = repmat(1/Ns, 1, Ns);          % now all particles have the same weight
return;  % bye, bye!!!