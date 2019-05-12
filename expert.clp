(deftemplate scoresData
	(slot groupNum)		;����� ������
	(slot surname)		;���
	(slot difficultQ)	;���������� ���������� ������� ��������
	(slot mediumQ)		;���������� ���������� �������� ������� ���������
	(slot easyQ)		;���������� ���������� ������ ��������
	(slot numQ)			;���������� �������� ��������
	(slot numClasses)	;���������� ����������� �������
	(slot skipClasses)	;���������� ����������� �������
	(slot pref)			;����������� ������������
	
)

(defrule rule1
	(scoresData	(groupNum ?groupNum)(surname ?surname)(difficultQ ?difficultQ)(mediumQ ?mediumQ)(easyQ ?easyQ)(numQ ?numQ)(numClasses ?numClasses)(skipClasses ?skipClasses)(pref ?pref))
	=>
	(printout t "")
)

(defrule rule2
	(scoresData (groupNum ?groupNum))
	(test (<= ?groupNum 8000))
	=>
	(printout t "�������� ������. ")
)


(defrule rule3
	(scoresData	(difficultQ ?difficultQ)(mediumQ ?mediumQ)(numQ ?numQ)(numClasses ?numClasses)(skipClasses ?skipClasses)(pref ?pref))
	(test (and ( >= ?difficultQ ( div ?numQ 4 ) )( >= ?mediumQ ( div ?numQ 4 ) ) ))
	=>
	(printout t (- (* 5 ?pref) (* 0.5 (/ ?skipClasses ?numClasses))))
)

(defrule rule4
	(scoresData	(difficultQ ?difficultQ)(mediumQ ?mediumQ)(easyQ ?easyQ)(numQ ?numQ)(numClasses ?numClasses)(skipClasses ?skipClasses)(pref ?pref))
	(test (and 	( < ?difficultQ ( div ?numQ 4 ) ) ( >= ?difficultQ ( div ?numQ 10 ) ) 
				( < ?mediumQ ( div ?numQ 4 ) ) ( >= ?mediumQ ( div ?numQ 6 ) ) 
				( >= ?easyQ ( div ?numQ 3 ))))
	=>
	(printout t (- (* 4 ?pref) (* 0.5 (/ ?skipClasses ?numClasses))))
)

(defrule rule5
	(scoresData	(mediumQ ?mediumQ)(easyQ ?easyQ)(numQ ?numQ)(numClasses ?numClasses)(skipClasses ?skipClasses)(pref ?pref))
	(test (and 	( <= ?mediumQ ( div ?numQ 6 ) ) ( > ?mediumQ ( div ?numQ 10 ) ) 
				( > ?easyQ ( div ?numQ 3 ))))
	=>
	(printout t (- (* 3 ?pref) (* 0.5 (/ ?skipClasses ?numClasses))))
)

(defrule rule5
	(scoresData	(mediumQ ?mediumQ)(easyQ ?easyQ)(numQ ?numQ)(numClasses ?numClasses)(skipClasses ?skipClasses)(pref ?pref))
	(test ( < ?easyQ ( div ?numQ 3 )))
	=>
	(printout t (- (* 2 ?pref) (* 0.5 (/ ?skipClasses ?numClasses))))
)