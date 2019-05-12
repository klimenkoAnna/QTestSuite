;;*************************************************************************
;;*                 ������ �������� ��������� "������"                      *
;;*************************************************************************

(deftemplate Question 							;;
  (slot Id(type NUMBER))						;;���������� ������������� �������
  (slot Topic(type NUMBER))						;;���� ������� ��� �������� �����, ������� � 1
  (slot Text(type NUMBER))						;;���������� ��� ������
  (slot Answer1(type NUMBER))					;;������ 1
  (slot Answer2(type NUMBER))					;;2
  (slot Answer3(type NUMBER))					;;3
  (slot Answer4(type NUMBER))					;;4
  (slot CorrectAnswer(type NUMBER))				;;���������� �����
  (slot Complexity(type NUMBER))  				;; ���������: 1-����� 2-������ 3-������
  (slot Status(type NUMBER))		;;0 - �� �������������� 1 - ��������������
)

;;*************************************************************************
;;*               ������������� ��������������� ����������                *
;;*************************************************************************
(defglobal
	?*Num* = 2									;;���-�� ��������, ������� ������ ���� ������ 
) 

(deffunction Num_minus()												
  (bind ?*Num* (- ?*Num* 1))
  ?*Num*
)

(deffunction Get_Num()
  ?*Num*
)

;;*************************************************************************
;;*               ������������� ��������������� ����������                *
;;*************************************************************************
(deffacts start
	(currentComplexity 1)
	(currentTopic 1)
	(changeTopic no)
)

(defrule begin
	(initial-fact)
	=>
	(load-facts q)
	)
;*************************************************************************
;;*                       ������� �������� ���������                      *
;;*************************************************************************

(defrule StopTest															
	(declare (salience 200))
	(test (= ?*Num* 0))															;;����� ������� ������� �� ����������� ���-�� ��������
	=>
	(halt)																	;;��������� ���������� ��������
	(printout t " The test is over" crlf)									;; � ������ ���������
)

;;*************************************************************************
;;*                      �������� ���������� ��������                     *
;;*************************************************************************

;(defrule RemoveAnswered
;	(declare (salience 1000))
;	(Question (Status 1))													;;���� ������� �� �������� 1, �.�. �������������(����������)
;	?f<-(Question (Status 1))
;	=>
;	(retract ?f)															;;� ������� ��, ����� �� ������ ��������
;)

;;*************************************************************************
;;*                             ����� �������                             *
;;*************************************************************************
(deffunction ask-question (?text ?a1 ?a2 ?a3 ?a4 ?CorrectAnswer)
   (printout t "������ " ?text crlf "�������� ������ " ?a1 "  " ?a2 "  " ?a3 "  " ?a4 crlf )
   (bind ?answer (read))
   (if (= ?CorrectAnswer ?answer) 
        then TRUE
		else FALSE
	)
 )
 
 
;;*************************************************************************
;;*                             ������ ����                               *
;;*************************************************************************
(defrule change-topic
	(declare (salience 150))
	(changeTopic yes)
	?fC <- (changeTopic yes)
	?fT <- (currentTopic ?cT)
	?fQ <- (Question (Topic ?topic & :(!= ?topic ?cT)))
	=>
	(retract ?fC ?fT)
	(assert (changeTopic no))
	(assert (currentTopic ?topic))

)

;;*************************************************************************
;;*                             ������ ������                             *
;;*************************************************************************

(defrule AskQuestion_1
	(declare (salience 100))
	(currentComplexity 1)
	?fTopic <- (currentTopic ?curTopic)
	?fC<-(currentComplexity ?cC)
	?fCh <- (changeTopic no)
	?fQuestion<-(Question (Topic ?topic & :(= ?topic ?curTopic))(Text ?text)
					(Answer1 ?a1)(Answer2 ?a2)(Answer3 ?a3)(Answer4 ?a4)
					(CorrectAnswer ?correctanswer)(Complexity ?complexity & :(= ?complexity 1))
					(Status 0))
	=>
	(if(ask-question ?text ?a1 ?a2 ?a3 ?a4 ?correctanswer)
		then 	(retract ?fC)
				(assert(currentComplexity 2))
				
		else (modify ?fCh (changeTopic yes))				
	)
	
)

 (defrule AskQuestion_2
	(declare (salience 100))
	(currentComplexity 2)
	?fTopic <- (currentTopic ?curTopic)
	?fC<-(currentComplexity ?cC)
	?fCh <- (changeTopic no)
	?fQuestion <- 	(Question 	(Id ?id) (Topic ?topic & :(= ?topic ?curTopic)) (Text ?text) 
						(Answer1 ?a1) (Answer2 ?a2) (Answer3 ?a3) (Answer4 ?a4)
						(CorrectAnswer ?correctanswer) (Complexity ?complexity & :(= ?complexity 2))  
						(Status ?status & :(= ?status 0))
			)
	=>
	((if(ask-question ?text ?a1 ?a2 ?a3 ?a4 ?correctanswer)
		then(modify ?fC (currentComplexity 3))
		else(modify ?fC (currentComplexity 1))				
	)
	(modify ?fQuestion (Status 1))
	Num_minus)
)

(defrule AskQuestion_3
	(declare (salience 100))
	(currentComplexity 3)
	?fTopic <- (currentTopic ?curTopic)
	?fC<-(currentComplexity ?cC)
	?fCh <- (changeTopic no)
	?fQuestion <- 	(Question (Id ?id) (Topic ?topic & :(= ?topic ?curTopic)) (Text ?text) 
						(Answer1 ?a1) (Answer2 ?a2) (Answer3 ?a3) (Answer4 ?a4)
						(CorrectAnswer ?correctanswer) (Complexity ?complexity & :(= ?complexity 3))  
						(Status ?status & :(= ?status 0))
			)
	=>
	((if(ask-question ?text ?a1 ?a2 ?a3 ?a4 ?correctanswer)
		then (modify ?fC (currentComplexity 1))
			 (modify ?fCh (changeTopic yes))
		else(modify ?fC (currentComplexity 2))				
	)
	(modify ?fQuestion (Status 1))
	Num_minus)
)


