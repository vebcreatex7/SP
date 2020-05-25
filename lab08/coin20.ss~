;(define (count-change amount)
; (cc amount 6))

(define variant 3)
(define last-digit-of-group-number 6)
(define kinds-of-coins 6)

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount
                        (first-denomination kinds-of-coins))
                     kinds-of-coins)))))

(define (count-change amount kinds-of-coins)
  (display "count-change for ")
  (display amount)
  (display " ")
  (display kinds-of-coins)
  (display "\t= ")
  (if (let()(and (> amount 0) (> kinds-of-coins 0) (> (first-denomination kinds-of-coins) 0)))
      (cc amount kinds-of-coins)
      (let()(display "(improper parametr value)") 0)))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 2)
        ((= kinds-of-coins 3) 3)
        ((= kinds-of-coins 4) 20)
        ((= kinds-of-coins 5) 25)
        ((= kinds-of-coins 6) 50)
        (0)))


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

        

