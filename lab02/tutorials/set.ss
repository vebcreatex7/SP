; set
(define a 7)
(define(g x a)
  (set! a 5)
  (+ x a)
)
(display"(g 1 0)=")(display(g 1 0))(newline)
(display "a=")(display a)(newline)
(set! a 8)
a
;_______________
