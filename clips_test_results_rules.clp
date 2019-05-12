(deftemplate scoresData
	(slot minScore)
	(slot maxScore)
	(slot maxPossibleScore)
	(slot groupNum)
	(slot surname)
)

(defrule rule1
	(scoresData (minScore ?minScore) (maxScore ?maxScore) (maxPossibleScore ?maxPossibleScore) (groupNum ?groupNum) (surname ?surname))
	=>
	(printout t "")
)

(defrule rule2
	(scoresData (groupNum ?groupNum))
	(test (<= ?groupNum 8000))
	=>
	(printout t "Тестовая группа. ")
)

(defrule rule3
	(scoresData (maxScore ?maxScore) (maxPossibleScore ?maxPossibleScore))
	(test ( <= ?maxScore ( * ?maxPossibleScore 0.25 ) ) )
	=>
	(printout t "Низкий балл. ")
)

(defrule rule4
	(scoresData (maxScore ?maxScore) (maxPossibleScore ?maxPossibleScore))
	(test ( >= ?maxScore ( * ?maxPossibleScore 0.75 ) ) )
	=>
	(printout t "Высокий балл. ")
)