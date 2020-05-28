;golden-section20

(define(NOT? x?)
  (= 0 (cond (x? 1) (else 0)))
)

(define a 6)(define b 8);7.27356
(define (fun x)
  (set! x (- x (/ 103 104)))
  (- (- x  (sin x)) (cos x)))
(define (golden-section-search a b)
 (let(
      (xmin(cond((NOT? (<= b a))(golden-start a b)) (else (golden-start b a))))
     )
     (newline)
     xmin
 )
)
(define (golden-start a b)
 (let(
      (xa (+ a (* mphi(- b a))))
      (xb (- b (* mphi(- b a))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)
(define mphi (* +0.5 (- 3(sqrt 5))))

(define (try a b xa ya xb yb)


   (cond ((close-enough? a b) (* (+ a b) +0.5))
        (else (let() (display "+")
                (cond((NOT? (<= yb ya)) (let()
                                          (set! b xb)
                                          (set! xb xa)
                                          (set! yb ya)
                                          (set! xa ( + a (* mphi (- b a))))
                                          (try a b  xa (fun xa) xb yb)))
                     (else (let()
                             (set! a xa)
                             (set! xa xb)
                             (set! ya yb)
                             (set! xb (- b(* mphi(- b a))))
                             (try a b xa ya xb (fun xb)))
                     )
                )
              )
         )
   )
)

(define (close-enough? x y)

  (NOT? (<= tolerance (abs (- x y))))
)
(define tolerance +0.00001)
(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)
