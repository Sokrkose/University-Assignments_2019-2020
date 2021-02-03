echo_code = "E8438";
image_code = "M8102";
audio_code = "A0005";
ithakicopter_code = "Q4192";
vehicle_code = "V2954";

load responsetimes60.csv
load throughputs60.csv
load responsetimesE000060.csv
load throughputsE000060.csv

%G1
figure
bar(responsetimes60)
legend("Packets response times with Delay")
xlabel("Packet")
ylabel("Response Time")
title(["G1 - Packets response times with Delay - " echo_code])

%G2
y = (throughputs60) * 128;
figure
bar(y(1:length(y)-floor(8/mean(y))-1))
legend("Packet Rates with Delay")
xlabel("Time")
ylabel("BYTES per second")
title(["G2 - Packet Rates with Delay - " echo_code])

%G3
figure
bar(responsetimesE000060)
legend("Packets response times without Delay")
xlabel("Packet")
ylabel("Response Time")
title(["G3 - Packets response times without Delay - " echo_code])

%G4
y = (throughputsE000060)*128;
figure
bar(y(1:length(y)-floor(8/mean(y))-1))
legend("Packet Rates without Delay")
xlabel("Time")
ylabel("BYTES per second")
title(["G4 - Packet Rates without Delay - " echo_code])

%G5
y = responsetimes60;
figure
hist(y)
xlabel("Number of packages")
ylabel("Response Time")
title(["G5 - Propability of Packet Times with Delay - " echo_code])

%G6
y = (throughputs60)*128;
y = y(1:length(y)-floor(8/mean(y))-7);
figure
hist(y)
xlabel("Packet Rate")
ylabel("Probability")
title(["G6 - Propability of Rates with Delay - " echo_code])

%G7
y = responsetimesE000060;
figure
hist(y)
xlabel("Number of packages")
ylabel("Response Time")
title(["G7 - Propability of Packet Times without Delay - " echo_code])

%G8
y = (throughputsE000060)*128;
y = y(1:length(y)-floor(8/mean(y))-7);
figure
hist(y)
xlabel("Packet Rate")
ylabel("Probability")
title(["G8 - Propability of Rates with Delay - " echo_code])


load Temperatures.csv

%E1
figure
plot(Temperatures)
ylabel('Degrees Celcius')
xlabel('Time')
title(['T1 - Temperature - ' echo_code 'T00'])


load DPCMfreq_SIN.csv
load DPCMfreq_Clip.csv
load DPCMdiffs_Clip.csv

load AQDPCMsamples.csv
load AQDPCMdiffs.csv
load AQDPCMstepfile.csv
load AQDPCMmeanfile.csv

load AQDPCMsamples1.csv
load AQDPCMdiffs1.csv
load AQDPCMstepfile1.csv
load AQDPCMmeanfile1.csv

%G9
figure
plot(DPCMfreq_SIN)
title(["G9 - Sine wave Sample - " audio_code])

%G10
figure
plot(DPCMfreq_Clip)
title(["G10 - Clip Sample - " audio_code])

%G11
y = DPCMfreq_Clip;
figure
hist(y(:,1),49)
ylabel("Frequency")
title(["G11 - DPCM Propability of sample - " audio_code])

%G12
y = DPCMdiffs_Clip;
figure
hist(y(:,1),16)
ylabel("Frequency")
title(["G12 - DPCM Propability of differentials - " audio_code])

%G13
y = AQDPCMsamples;
figure
hist(y(200:end,1),80)
ylabel("Frequency")
title(["G13 - AQDPCM Propability of sample - " audio_code])

%G14
y = AQDPCMdiffs;
figure
hist(y(:,1),16)
ylabel("Frequency")
title(["G14 - AQDPCM Propability of differentials - " audio_code])

%G15 
figure
plot(AQDPCMmeanfile(2:end))
title(["G15 - AQDPCM Mean Values - Clip 8 - " audio_code])

%G16 
figure
plot(AQDPCMstepfile(2:end))
title(["G16 - AQDPCM Quantizer Step - Clip 8 - " audio_code])

%G15 
figure
plot(AQDPCMmeanfile1(2:end))
title(["G17 - AQDPCM Mean Values - Clip 7 - " audio_code])

%G16 
figure
plot(AQDPCMstepfile1(2:end))
title(["G18 - AQDPCM Quantizer Step - Clip 7 - " audio_code])



load altitude.csv
load leftMotor.csv
load rightMotor.csv
load pressure.csv
load temperature.csv

load altitude1.csv
load leftMotor1.csv
load rightMotor1.csv
load pressure1.csv
load temperature1.csv

%G19
figure
subplot(2,2,1)
plot(leftMotor)
hold on 
plot(rightMotor)
title(['Left & Right Motors - ' ithakicopter_code])

subplot(2,2,2)
plot(altitude)
title(['Altitude - Flight Level 1 - ' ithakicopter_code])

subplot(2,2,3)
plot(temperature)
ylabel('Degrees Celcius')
title(['Temperature - ' ithakicopter_code])

subplot(2,2,4)
plot(pressure)
ylabel('milliBars')
title(['Atmospheric Pressure - ' ithakicopter_code])


%G20
figure
subplot(2,2,1)
plot(leftMotor1)
hold on 
plot(rightMotor1)
title(['Left & Right Motors - ' ithakicopter_code])

subplot(2,2,2)
plot(altitude1)
title(['Altitude - Flight Level 2 - ' ithakicopter_code])

subplot(2,2,3)
plot(temperature1)
ylabel('Degrees Celcius')
title(['Temperature - ' ithakicopter_code])

subplot(2,2,4)
plot(pressure1)
ylabel('milliBars')
title(['Atmospheric Pressure - ' ithakicopter_code])



load vehicleLog_0C.csv
load vehicleLog_0D.csv
load vehicleLog_0F.csv
load vehicleLog_1F.csv
load vehicleLog_05.csv
load vehicleLog_11.csv

figure

subplot(2,3,1)
plot(vehicleLog_1F)
title(['Engine Run Time - ' vehicle_code])
ylabel('Seconds')

subplot(2,3,2)
plot(vehicleLog_0F)
title(['Intake Air Temperature - ' vehicle_code])
ylabel('°C')

subplot(2,3,3)
plot(vehicleLog_11)
title(['Throttle Position - ' vehicle_code])
ylabel('%')

subplot(2,3,4)
plot(vehicleLog_0C)
title(['Engine RPM - ' vehicle_code])
ylabel('RPM')

subplot(2,3,5)
plot(vehicleLog_0D)
title(['Vehicle Speed - ' vehicle_code])
ylabel('Km/h')

subplot(2,3,6)
plot(vehicleLog_05)
title(['Coolant Temperature - ' vehicle_code])
ylabel('°C')
