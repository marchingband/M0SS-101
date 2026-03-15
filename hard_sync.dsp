import("stdfaust.lib");

blep_this(x) = 0.5 * x * x;
blep_next(x) = -0.5 * (1.0 - x) * (1.0 - x);
sq(phase, pw) = phase >= pw;

hard_sync_sq_slave(m_freq, s_freq, pw) = (next, high, m_phase, s_phase, prev_pw, out) : !,!,!,!,!,_ : _*2-1
letrec{
    'prev_pw = pw;
    'out = 
        next 
        - ba.if(
            reset,
            sq(fmod(slave_phase_at_reset, 1.0), pw) * blep_this(reset_time),
            0
        )
        + ba.if(
            (transition_during_reset + (reset == 0)) > 0,
            ba.if(
                high,
                ba.if(
                    s_phase_ >= 1.0,
                    -(blep_this(s_phase__ / s_step)),
                    0
                ),
                ba.if(
                    s_phase_ >= pw,
                    blep_this((s_phase_ - pw) / (prev_pw - pw + s_step)),
                    0
                )
            ),
            0
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
            slave_phase_at_reset = s_phase + (1.0 - reset_time) * s_step;
            transition_during_reset = (slave_phase_at_reset >= 1.0) + ((high == 0) + (slave_phase_at_reset >= pw) == 2) > 0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
        };
    'next = 
        sq(s_phase___, pw) 
        - ba.if(
            reset,
            sq(fmod(slave_phase_at_reset, 1.0), pw) * blep_next(reset_time),
            0
        )
        + ba.if(
            (transition_during_reset + (reset == 0)) > 0,
            ba.if(
                high,
                ba.if(
                    s_phase_ >= 1.0,
                    -(blep_next(s_phase__ / s_step)),
                    0
                ),
                ba.if(
                    s_phase_ >= pw,
                    blep_next((s_phase_ - pw) / (prev_pw - pw + s_step)),
                    0
                )
            ),
            0
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
            slave_phase_at_reset = s_phase + (1.0 - reset_time) * s_step;
            transition_during_reset = (slave_phase_at_reset >= 1.0) + ((high == 0) + (slave_phase_at_reset >= pw) == 2) > 0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
            s_phase___ = ba.if(reset, reset_time * s_step, s_phase__);
        };
    's_phase = 
        ba.if(
            reset,
            reset_time * s_step,
            fmod(s_phase + s_step, 1.0)
        )
        with{
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
        };
    'm_phase = fmod(m_phase + m_step, 1.0);
    'high = 
        ba.if(
            (reset + (high + (s_phase_ >= 1.0) == 2) + ((high == 0) + (s_phase__ < pw) == 2)) > 0, 
            0,
            1
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
        };
}
with {
    m_step = m_freq / ma.SR;
    s_step = s_freq / ma.SR;
};

hard_sync_sq_master(s_freq, pw) = (next, high, s_phase, prev_pw, out) : !,!,!,!,_ : _*2-1
letrec{
    'prev_pw = pw;
    'out = 
        next 
        + ba.if(
            high,
            ba.if(
                s_phase_ >= 1.0,
                -(blep_this(s_phase__ / s_step)),
                0
            ),
            ba.if(
                s_phase_ >= pw,
                blep_this((s_phase_ - pw) / (prev_pw - pw + s_step)),
                0
            )
        )
        with {
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
        };
    'next = 
        sq(s_phase___, pw) 
        + ba.if(
            high,
            ba.if(
                s_phase_ >= 1.0,
                -(blep_next(s_phase__ / s_step)),
                0
            ),
            ba.if(
                s_phase_ >= pw,
                blep_next((s_phase_ - pw) / (prev_pw - pw + s_step)),
                0
            )
        )
        with {
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
            s_phase___ = s_phase__;
        };
    's_phase = fmod(s_phase + s_step, 1.0);
    'high = 
        ba.if(
            ((high + (s_phase_ >= 1.0) == 2)) + ((high == 0) + (s_phase__ < pw) == 2) > 0, 
            0,
            1
        )
        with {
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
        };
}
with {
    m_step = m_freq / ma.SR;
    s_step = s_freq / ma.SR;
};

hard_sync_variable_slave(m_freq, s_freq, _pw, ws) = (next, high, m_phase, s_phase, prev_pw, out) : !,!,!,!,!,_ : _*2-1
letrec{
    'prev_pw = pw;
    'out = 
        next 
        - ba.if(
            reset,
            var(fmod(slave_phase_at_reset, 1.0), pw, slope_up, slope_down, tri_amount, sq_amount) * blep_this(reset_time),
            0
        )
        + ba.if(
            (transition_during_reset + (reset == 0)) > 0,
            ba.if(
                high,
                ba.if(
                    s_phase_ >= 1.0,
                    (triangle_step * i_blep_this(s_phase__ / s_step)) - ((1.0 - tri_amount) * blep_this(s_phase__ / s_step)),
                    0
                ),
                ba.if(
                    s_phase_ >= pw,
                    ((1.0 - tri_amount) * blep_this((s_phase_ - pw) / (prev_pw - pw + s_step))) - (triangle_step * i_blep_this((s_phase_ - pw) / (prev_pw - pw + s_step))),
                    0
                )
            ),
            0
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
            slave_phase_at_reset = s_phase + (1.0 - reset_time) * s_step;
            transition_during_reset = ((slave_phase_at_reset >= 1.0) + ((high == 0) + (slave_phase_at_reset >= pw) == 2)) > 0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
            triangle_step = (slope_up + slope_down) * s_step * tri_amount;
        };
    'next = 
        var(s_phase___, pw, slope_up, slope_down, tri_amount, sq_amount) 
        - ba.if(
            reset,
            var(fmod(slave_phase_at_reset, 1.0), pw, slope_up, slope_down, tri_amount, sq_amount) * blep_next(reset_time),
            0
        )
        + ba.if(
            (transition_during_reset + (reset == 0)) > 0,
            ba.if(
                high,
                ba.if(
                    s_phase_ >= 1.0,
                    (triangle_step * i_blep_next(s_phase__ / s_step)) - ((1.0 - tri_amount) * blep_next(s_phase__ / s_step)),
                    0
                ),
                ba.if(
                    s_phase_ >= pw,
                    ((1.0 - tri_amount) * blep_next((s_phase_ - pw) / (prev_pw - pw + s_step))) - (triangle_step * i_blep_next((s_phase_ - pw) / (prev_pw - pw + s_step))),
                    0
                )
            ),
            0
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
            slave_phase_at_reset = s_phase + (1.0 - reset_time) * s_step;
            transition_during_reset = (slave_phase_at_reset >= 1.0) + ((high == 0) + (slave_phase_at_reset >= pw) == 2) > 0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
            s_phase___ = ba.if(reset, reset_time * s_step, s_phase__);
            triangle_step = (slope_up + slope_down) * s_step * tri_amount;
        };
    's_phase = 
        ba.if(
            reset,
            reset_time * s_step,
            fmod(s_phase + s_step, 1.0)
        )
        with{
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            m_phase__ = fmod(m_phase_, 1.0);
            reset_time = m_phase__ / m_step;
        };
    'm_phase = fmod(m_phase + m_step, 1.0);
    'high = 
        ba.if(
            (reset + (high + (s_phase_ >= 1.0) == 2) + ((high == 0) + (s_phase__ < pw) == 2)) > 0, 
            0,
            1
        )
        with {
            m_phase_ = m_phase + m_step;
            reset = m_phase_ >= 1.0;
            s_phase_ = s_phase + s_step;
            s_phase__ = fmod(s_phase_, 1.0);
        };
}
with {
    m_step = m_freq / ma.SR;
    s_step = s_freq / ma.SR;
    sq_amount = max(ws - 0.5, 0.0) * 2.0;
    tri_amount = max(1.0 - ws * 2.0, 0.0);
    slope_up = 1.0 / (pw);
    slope_down = 1.0 / (1.0 - pw);
    pw = ba.if(s_step >= 0.25, 0.5, max(s_step * 2.0, min(1.0 - 2.0 * s_step)), _pw);
};

m = hslider("m", 100, 10, 10000, 0.01) : si.smoo;
s = hslider("s", 100, 10, 10000, 0.01) : si.smoo;
pw = hslider("pw", 0.0, 0.0, 1.0, 0.001) : si.smoo;
ws = hslider("ws", 0.0, 0.0, 1.0, 0.001) : si.smoo; // 0 == triangle, 1 == square

// process = hard_sync_sq_slave(m, s, pw);
// process = hard_sync_sq_master(m, pw);
// process = hard_sync_saw_slave(m, s);
// process = hard_sync_saw_master(m);
process = hard_sync_variable_slave(m, s, pw, ws);


// process = hard_sync_sq_master(m, pw), hard_sync_sq_slave(m, s, pw);
// process = hard_sync_saw_master(m), hard_sync_saw_slave(m, s);
