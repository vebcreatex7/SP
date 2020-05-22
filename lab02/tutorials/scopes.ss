; scopes
(define a 7)
(define(f f)
  (set! f (- f (/ 100 101)))
  (let(
       (a (sin f))
       (b (log f))
       (f 0)
      )
      (set! f (* 5 a b))
      (display "f=")(display f)(newline)
    f
  )
)
(f 1)
;_______________
