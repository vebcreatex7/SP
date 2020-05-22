; block
(define(f x)
  (set! x (- x (/ 100 101)))
  (let(
       (a (sin x))
       (b (log x))
       (f 0)
      )
      (set! f (* 5 a b))
      (display "f=")(display f)(newline)
    f
  )
)
(f 1)
