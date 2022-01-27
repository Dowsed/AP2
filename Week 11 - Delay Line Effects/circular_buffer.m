[delta, Fs] = audioread("Kronecker_Delta_MONO.wav");
delay_time = 5;
circ_buf = zeros(delay_time + 2, 1);
t = 1;
write_pos = 1;
read_pos = write_pos + delay_time;
if read_pos > length(circ_buf)
    read_pos = read_pos - length(circ_buf);
end

while t <= length(circ_buf) + 2

    %add new element to buffer
    circ_buf(write_pos, 1) = delta(t,1);

    % increment and check write pointer
    write_pos = write_pos + 1;
    if write_pos > length(circ_buf)
        write_pos = write_pos - length(circ_buf);
    end

    % increment and check read pointer
    read_pos = write_pos + delay_time;
    if read_pos > length(circ_buf)
        read_pos = read_pos - length(circ_buf);
    end

    t = t + 1;
end