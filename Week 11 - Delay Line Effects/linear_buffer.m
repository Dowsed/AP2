[delta, Fs] = audioread("Kronecker_Delta_MONO.wav");
delta(2,1) = 0.2;
delay_time = 5;
lin_buf = zeros(delay_time + 2, 1);
t = 1;

while t <= length(lin_buf) + 2
    % shift all elements already in the delay line ready for a new element
    for n = length(lin_buf):-1:1
        if n ~= 1
        lin_buf(n,1) = lin_buf(n-1,1);
        end
    end
    % add new elements from delta (as long as there are new elements to
    % add)
    if t <= length(delta)
        lin_buf(1,1) = delta(t,1);
    end
    t = t + 1;
end
