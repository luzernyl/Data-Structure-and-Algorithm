re = [
20 7607.3
40 18436.7
60 25090.2
80 41452.9
100 57676.3
120 76117.8
140 84185.7
160 102081
180 149209
200 158950
220 198629
240 213646
260 226249
280 261316
300 322553
320 317202
340 390405
360 386582
380 479181
400 440773
];
plot(re(:, 1).*log(re(:,1)), re(:, 2), '.','MarkerSize',20);
xlabel('Problem Size : nlogn');
ylabel('Time Efficiency : t_n');
set(gca,'FontSize',20);
