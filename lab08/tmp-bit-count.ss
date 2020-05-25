;bit-count
(define(even-bits n)
  (cond ((= n 0) 1)
        (else(cond ((= (remainder n 2)0) (even-bits (quotient n 2)))
                   (else (odd-bits(quotient n 2)))
             )
        )
  )
)
(define(odd-bits n)


  (cond((= n 0) 0)
       (else(cond((= (remainder n 2) 0) (odd-bits(quotient n 2)))
                 (else (even-bits(quotient n 2)))
             )
       )
  )

)
(define(bit-count n)

  (cond ((= n 0) 0)
        (else (+(remainder n 2) (bit-count(quotient n 2))))
  )
  
)
(define(report-results n)
  (display "Happy birthday to you!\n\t")
  (display n)(newline)
  (display "\teven?\t")(display (if(=(even-bits n)1) "yes" "no"))
  (newline)
  (display "\todd?\t")(display (if(=(odd-bits n)1) "yes" "no"))
  (newline)
  (display "bit-count = ")
  (bit-count n)
)
;***** Date of YOUR birthday *******
(define dd 31)
(define mm 01)
(define yyyy 2000)
;***********************************
(report-results (+ (* dd 1000000)
                   (* mm 10000)
                   yyyy))


 
