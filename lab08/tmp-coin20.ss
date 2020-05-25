
(define(NOT? x?)
  (= 0 (cond (x? 1) (else 0)))
)

(define (implication? x? y?)
  (NOT? (and x? (NOT? y?)))
)

(define variant 3)
(define last-digit-of-group-number 6)
(define kinds-of-coins 6)

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        (else (cond((implication?  (<= 0 amount) (= kinds-of-coins 0)) 0)
                   (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount
                        (first-denomination kinds-of-coins))
                     kinds-of-coins))
                   )
              )
        )
  )
)


(define (count-change amount kinds-of-coins)
  (display "count-change for ")
  (display amount)
  (display " ")
  (display kinds-of-coins)
  (display "\t= ")

  (cond ((and (NOT? (<= amount 0)) (NOT? (<= kinds-of-coins 0 )) (NOT? (<= (first-denomination kinds-of-coins) 0))) (cc amount kinds-of-coins))
        (else (let() (display "(improper parametr value)") 0)
        )
  )

)
(define (first-denomination kinds-of-coins)

  (cond ((= kinds-of-coins 1) 1)
        (else (cond ((= kinds-of-coins 2) 2)
                    (else (cond ((= kinds-of-coins 3) 3)
                                (else (cond ((= kinds-of-coins 4) 20)
                                            (else (cond ((= kinds-of-coins 5) 25)
                                                        (else (cond ((= kinds-of-coins 6) 50)
                                                                    (else 0)
                                                              )
                                                        )
                                                  )
                                             )
                                       )
                                  )
                            )
                     )
               )
         )
    )
)


(define (gr-amount)
  (remainder (+(* 100 last-digit-of-group-number) variant) 137))

(display "VKO variant ")
(display variant)
(newline)
(display " 1-2-3-20-25-50")
(newline)
(display (count-change 100 kinds-of-coins))
(newline)
(display (count-change (gr-amount) kinds-of-coins))
(newline)
(display (count-change 100 100))
(newline)
(display (gr-amount))

        

