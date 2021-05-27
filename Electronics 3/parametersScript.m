AEM=37;

CL = (2+0.01*AEM)*10^(-12);
SRmin = (18+0.01*AEM)*10^(6);
Vdd = 1.8+0.003*AEM;
Vss = -Vdd;
GBmin = (7+0.01*AEM) * 10^(6);
Amin = (20+0.01*AEM);
Pmax = (50+0.01*AEM)*10^(-3);

VTon = 0.7860;
kn = 100*10^(-6);
k1 = kn;
k2 = kn;
k5 = kn;
k7 = kn;
k8 = kn;

VTop = -0.9056;
kp = 50*10^(-6);
k3 = kp;
k4 = kp;
k6 = kp;
Cox = 2.3*10^(-3);
Vinmax = 100*10^(-3);
Vinmin = -100*10^(-3);


L = 1*10^(-6);

Ccmin=0.22*CL;

I5min = Ccmin*SRmin;

S3 = ceil(I5min / (k3*(Vdd - Vinmax - abs(VTop) + VTon)^2));
S4 = S3;

p3=sqrt(kp* S3 * I5min)/(2 * 0.667 * S3 * (L^2) * Cox);

gm1 = 2*pi*GBmin*Ccmin;
gm2=gm1;
S1 = ceil(gm1^2/(k2*I5min));
S2=S1;

b1 = k1*S1;
VT1 = VTon;
VDs5_sat = Vinmin - Vss - sqrt(I5min/b1)-VT1;
S5 = ceil((2*I5min)/(k5*(VDs5_sat)^2));
S8=S5;

gm4 = sqrt(2 * kp * S4 * I5min/2);
gm6 = 2.2*gm2*CL/Ccmin;
S6 = ceil(S4*gm6/gm4);
I6 = gm6^2/(2*k6*S6);

S7 = ceil(S5*I6/I5min);

ln = 0.05;
lp = 0.15;
Pdiss = (I5min+I6)*(Vdd + abs(Vss));
Av = 2*gm2*gm6/(I5min*I6*(ln+lp)^2);
Av_dB = 10*log10(Av);

W1 = S1 * L;
W2 = S2 * L;
W3 = S3 * L;
W4 = S4 * L;
W5 = S5 * L;
W6 = S6 * L;
W7 = S7 * L;
W8 = W5;