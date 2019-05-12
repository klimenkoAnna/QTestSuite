;;*************************************************************************
;;*                 Ўаблон описани€ структуры "вопрос"                      *
;;*************************************************************************

(deftemplate Question 							;;
  (slot Id(type NUMBER))						;;уникальный идентификатор вопроса
  (slot Topic(type NUMBER))						;;тема вопроса дл€ удобства номер, начина€ с 1
  (slot Text(type NUMBER))						;;собственно сам вопрос
  (slot Answer1(type NUMBER))					;;ответы 1
  (slot Answer2(type NUMBER))					;;2
  (slot Answer3(type NUMBER))					;;3
  (slot Answer4(type NUMBER))					;;4
  (slot CorrectAnswer(type NUMBER))				;;правильный ответ
  (slot Complexity(type NUMBER))  				;; сложность: 1-легко 2-средне 3-сложно
  (slot Status(type NUMBER))		;;0 - не рассматривалс€ 1 - рассмотривалс€
)

;;*************************************************************************
;;*               »нициализаци€ вспомогательных переменных                *
;;*************************************************************************

(deffacts start
	(currentComplexity 1)
	(currentTopic 1)
	(changeTopic no)
	
	(Question(Id 1)(Topic 1)(Text 1)(Answer1 2)(Answer2 3)(Answer3 1)
	(Answer4 4)(CorrectAnswer 1)(Complexity 1)(Status 0))
	
	(Question(Id 2)(Topic 1)(Text 2)(Answer1 2)(Answer2 3)(Answer3 1)
	(Answer4 4)(CorrectAnswer 2)(Complexity 2)(Status 0))
	
	(Question(Id 3)(Topic 1)(Text 3)(Answer1 2)(Answer2 3)(Answer3 1)
	(Answer4 4)(CorrectAnswer 3)(Complexity 3)(Status 0))
	
	(Question(Id 4)(Topic 7)(Text 4)(Answer1 2)(Answer2 3)(Answer3 1)
	(Answer4 4)(CorrectAnswer 4)(Complexity 1)(Status 0))
)


;;*************************************************************************
;;*                       ѕравила останова программы                      *
;;*************************************************************************

(defrule StopTest															

	(initial-fact)															;;когда студент ответил на необходимое кол-во вопросов
	=>
	(save-facts fl local Question) 
	(halt)																	;;программа прекращает работать
	(printout t " The test is over" crlf)									;; и выдает сообщение
)
