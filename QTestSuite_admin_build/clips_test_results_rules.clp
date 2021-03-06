;;*************************************************************************
;;*                 Инициализация слотов                                  *
;;*************************************************************************
(deftemplate scoresData
	(slot groupNum)					;номер группы(четырехзначное число) - integer
	(slot surname)					;имя(символьная строка) - string
	(slot minScore)					;минимальное оценка за вопросы - float
	(slot maxScore)					;максимальная оценка за вопросы -float
	(slot maxPossibleScore)				;общее количество заданных вопросов в тесте - float
	(slot numClasses)				;количество проведенных занятий - integer
	(slot visitedClasses)				;количество посещенных занятий - integer
	(slot bonuses)					;бонусы(одно занятие - максимум один бонус) -целые
	(slot presentation)				;Презентация(одна на тест) -

)


;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************

(defrule rule1
        (scoresData  (groupNum ?groupNum)
        (surname ?surname)
        (minScore ?minScore)
        (maxScore ?maxScore)
        (maxPossibleScore ?maxPossibleScore)
        (bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	=>
	  (printout t  "")
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
(defrule rule2
        (scoresData  (groupNum ?groupNum))
	(test (>= ?groupNum 8000))
=>
(printout t "Test group. ")
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;<40 % и одно из трех слабого уровня(посещаемость/активность/презентация)
(defrule rule3
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test (and 
			( < ?maxScore ( * ?maxPossibleScore 0.4 )) 
			(or 
				( < (/ ?visitedClasses ?numClasses) 0.75 )
				(<= (/ ?bonuses ?numClasses) 0.25)
				( = ?presentation 0)
			)
		)
	)
	=>
	(printout t "Test result: 2. Doesn't pass" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;<40 процентов, но все остальное отлично. Даем студенту шанс
(defrule rule4
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test (and 
			( < ?maxScore ( * ?maxPossibleScore 0.4 )) 
			( > (/ ?visitedClasses ?numClasses) 0.75 )
			(>= (/ ?bonuses ?numClasses) 0.25)
			( = ?presentation 1)
		)
	)
	=>
	(printout t "Test result: 2. But recommended another try" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>40 <50 и чего-то не хватает
(defrule rule5
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.4 )) (< ?maxScore ( * ?maxPossibleScore 0.5 )))
			(< (/ ?visitedClasses ?numClasses) 0.75 )
			(<= (/ ?bonuses ?numClasses) 0.25)
		)
	)

	=>	
	(printout t "Test result: 2. Doesn't pass2" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>40 <50, хорошая посещаемость, активность, презентация по темам теста. Даем студенту шанс
(defrule rule6
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.4 )) (< ?maxScore ( * ?maxPossibleScore 0.5 )))
			( >= (/ ?visitedClasses ?numClasses) 0.75 )
			(>= (/ ?bonuses ?numClasses) 0.25)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 2. But recommended another try" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>40 <50, много посещает и активный, но без презентации
(defrule rule7
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.4 )) (< ?maxScore ( * ?maxPossibleScore 0.5 )))
			( > (/ ?visitedClasses ?numClasses) 0.75 )
			(>= (/ ?bonuses ?numClasses) 0.25)
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result:2. But active student, but without presentation. Recommended another try" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>50 <70, отличные результаты. Студенты рекомендуется четверка
(defrule rule8
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.5 )) (< ?maxScore ( * ?maxPossibleScore 0.7 )))
			( >= (/ ?visitedClasses ?numClasses) 0.9 )
			(>= (/ ?bonuses ?numClasses) 0.5)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 3,but recommended 4(active person with presentation and bonuses)" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>50 <70, неплохие результаты и можно поставить 4 на усмотрение учителя
(defrule rule9
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.5 )) (< ?maxScore ( * ?maxPossibleScore 0.7 )))
			(and ( >= (/ ?visitedClasses ?numClasses) 0.8 ) ( < (/ ?visitedClasses ?numClasses) 0.9 ))
			(>= (/ ?bonuses ?numClasses) 0.3)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Результат: 3. На усмотрение преподавателя, но рекомендуется 4" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>50 <70, средние результаты
(defrule rule10
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.5 )) (< ?maxScore ( * ?maxPossibleScore 0.7 )))
			(and ( >= (/ ?visitedClasses ?numClasses) 0.5 ) ( < (/ ?visitedClasses ?numClasses) 0.8 ))
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 3" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>50 <70, средние результаты
(defrule rule11
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.5 )) (< ?maxScore ( * ?maxPossibleScore 0.7 )))
			(and ( >= (/ ?visitedClasses ?numClasses) 0.5 ) ( < (/ ?visitedClasses ?numClasses) 0.8 ))
			(>= (/ ?bonuses ?numClasses) 0.2)
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result: 3. But student without presentation" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>50 <70, но студент не активный и без презентации
(defrule rule12
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.5 )) (< ?maxScore ( * ?maxPossibleScore 0.7 )))
			( <= (/ ?visitedClasses ?numClasses) 0.75 )
			(<= (/ ?bonuses ?numClasses) 0.2)
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result: 3, but recommend ask him questions" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, отличные результаты и студенту рекомендуется пятерка
(defrule rule13
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			( >= (/ ?visitedClasses ?numClasses) 0.9 )
			(>= (/ ?bonuses ?numClasses) 0.7)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 4. But recommended 5(active, bonuses and presentation)" crlf)
)
;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, хорошие результаты результаты и студенту рекомендуется пятерка
(defrule rule14
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			(and ( >= (/ ?visitedClasses ?numClasses) 0.8 ) ( < (/ ?visitedClasses ?numClasses) 0.9 ))
			(>= (/ ?bonuses ?numClasses) 0.5)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 4. But can be 5, because active student" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, крепкая 4
(defrule rule15
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			(and (>= (/ ?visitedClasses ?numClasses) 0.5) (< (/ ?visitedClasses ?numClasses) 0.9) )
			(< (/ ?bonuses ?numClasses) 0.5)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 4" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, сдано на 4, но слабая активность и посещаемость
(defrule rule16
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			(and ( >= (/ ?visitedClasses ?numClasses) 0.5 ) ( < (/ ?visitedClasses ?numClasses) 0.7 ))
			(< (/ ?bonuses ?numClasses) 0.3)
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result: 4(but low attendance and activity)" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, сдано на 4, слабая посещаемость, но очень активный 
(defrule rule17
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			(<= (/ ?visitedClasses ?numClasses) 0.25 )
			(>= (/ ?bonuses ?numClasses) 0.15)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 4(low attendance, but very active)" crlf)
)


;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>70 <90, сдано на 4, но по остальным показателям плохо
(defrule rule18
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			( and (>= ?maxScore ( * ?maxPossibleScore 0.7 )) (< ?maxScore ( * ?maxPossibleScore 0.9 )))
			(<= (/ ?visitedClasses ?numClasses) 0.25 )
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result: 4, but recommend ask him questions" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>=90, сдано на 5
(defrule rule19
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			(> ?maxScore ( * ?maxPossibleScore 0.9 ))
			(>= (/ ?visitedClasses ?numClasses) 0.7 )
			(>= (/ ?bonuses ?numClasses) 0.5)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 5" crlf)
)


;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>=90, сдано на 5, но остальные параметры слабоваты
(defrule rule20
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			(> ?maxScore ( * ?maxPossibleScore 0.9 ))
			(>= (/ ?visitedClasses ?numClasses) 0.5 )
			(>= (/ ?bonuses ?numClasses) 0.25)
			( = ?presentation 0)
		)
	)

	=>
	(printout t "Test result: 5(but without presentation)" crlf)
)

;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>=90, сдано на 5, слабая посещаемость, но очень активный 
(defrule rule21
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			(> ?maxScore ( * ?maxPossibleScore 0.9 ))
			(<= (/ ?visitedClasses ?numClasses) 0.5 )
			(>= (/ ?bonuses ?numClasses) 0.25)
			( = ?presentation 1)
		)
	)

	=>
	(printout t "Test result: 5(low attendance, but very active)" crlf)
)


;;*************************************************************************
;;*                 Загрузка слотов                                       *
;;*************************************************************************
;>=90, сдано на 5, слабая посещаемость и активность.
(defrule rule22
	(scoresData  (groupNum ?groupNum)(surname ?surname)(minScore ?minScore)(maxScore ?maxScore)(maxPossibleScore ?maxPossibleScore)(bonuses ?bonuses)(numClasses ?numClasses)(visitedClasses ?visitedClasses)(presentation ?presentation))
	(test 
		(and 
			(> ?maxScore ( * ?maxPossibleScore 0.9 ))
			(<= (/ ?visitedClasses ?numClasses) 0.5 )
			(<= (/ ?bonuses ?numClasses) 0.25)
		)
	)

	=>
	(printout t "Test result: 5. But recommended ask him questions" crlf)
)












