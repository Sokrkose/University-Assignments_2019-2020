% Author: Sokratis Koseoglou
% Simple script for ploting the data of prod-cons multithreading example.

% First, import the data.

Means1(1:18) = 0;
Means2(1:24) = 0;

ConsThreads1 = [1,2,3,4,5,6,7,8,9,10,15,20,25,30,35,40,45,50];
ConsThreads2 = [1,10,20,30,40,50,60,70,80,90,100,120,140,150,170,190,200,225,250,275,300,350,400,500];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

counter = 1;
for i = 1:18
    A = results1(counter:(counter+4));
    Means1(i) = sum(A)/5;
    
    counter = counter + 5;
end

counter = 1;
for i = 1:24
    A = results2(counter:(counter+4));
    Means2(i) = sum(A)/5;
    
    counter = counter + 5;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

figure;
plot(ConsThreads1, Means1);
title('1 Producer Thread');
xlabel('Consumer Threads');
ylabel('Time in microseconds');

figure;
plot(ConsThreads2, Means2);
title('50 Producer Threads');
xlabel('Consumer Threads');
ylabel('Time in microseconds');
