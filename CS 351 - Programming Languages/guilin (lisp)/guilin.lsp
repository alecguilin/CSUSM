;; Alec Guilin
;; CS351
;; May 8 2019

(defun conve(phon_list)
    (cond ((null phon_list))
        ((eq(car (car phon_list)) 'A)
            (princ "Able")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'B)
            (princ "Baker")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'C)
            (princ "Charlie")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'D)
            (princ "Dog")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'E)
            (princ "Easy")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'F)
            (princ "Fox")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'G)
            (princ "George")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'H)
            (princ "How")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'I)
            (princ "Item")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'J)
            (princ "Jig")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'K)
            (princ "King")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'L)
            (princ "Love")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'M)
            (princ "Mike")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'N)
            (princ "Nan")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'O)
            (princ "Oboe")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'P)
            (princ "Peter")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'Q)
            (princ "Queen")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'R)
            (princ "Roger")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'S)
            (princ "Sugar")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'T)
            (princ "Tare")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'U)
            (princ "Uncle")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'V)
            (princ "Victor")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'W)
            (princ "William")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'X)
            (princ "Xray")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'Y)
            (princ "Yoke")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((eq(car (car phon_list)) 'Z)
            (princ "Zebra")(conve (cons (cdr (car phon_list))(cdr phon_list))))
        ((princ " ")(conve (cdr phon_list)))
))

(defun convp(eng_list)
    (cond ((null eng_list))
        ((string-equal(car (car eng_list)) "Able")
            (princ "A")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Baker")
            (princ "B")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Charlie")
            (princ "C")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Dog")
            (princ "D")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Easy")
            (princ "E")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Fox")
            (princ "F")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "George")
            (princ "G")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "How")
            (princ "H")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Item")
            (princ "I")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Jig")
            (princ "J")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "King")
            (princ "K")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Love")
            (princ "L")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Mike")
            (princ "M")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Nan")
            (princ "N")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Oboe")
            (princ "O")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Peter")
            (princ "P")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Queen")
            (princ "Q")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Roger")
            (princ "R")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Sugar")
            (princ "S")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Tare")
            (princ "T")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Uncle")
            (princ "U")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Victor")
            (princ "V")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "William")
            (princ "W")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Xray")
            (princ "X")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Yoke")
            (princ "Y")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((string-equal(car (car eng_list)) "Zebra")
            (princ "Z")(convp (cons (cdr (car eng_list))(cdr eng_list))))
        ((princ " ")(convp (cdr eng_list)))
))