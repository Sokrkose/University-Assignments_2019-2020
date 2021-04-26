load Session_2_echo.csv
load Session_2_ackNack.csv

echo = 'Echo: E8137 ';
ack = ' ACK: Q3111 ';
nack = ' NACK: R4942 ';

packets = [168 33 12 1 0 0 0 1];
times = [1 2 3 4 5 6 7 8];

%G1
figure
bar(Session_2_echo)
xlabel('Package')
ylabel('Response Times')
title(['G1.' echo ])
%saveas(gcf,'G1.png');

%G2
figure
bar(Session_2_ackNack)
xlabel('Package')
ylabel('Response Times')
title(['G2.' ack nack ])
%saveas(gcf,'G2.png');

%G3
figure
bar(times, packets)
xlabel('Number of times')
ylabel('Packages')
title(['G3.' ack nack ])
%saveas(gcf,'G3.png');

