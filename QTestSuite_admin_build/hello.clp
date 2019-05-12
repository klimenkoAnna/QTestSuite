(defrule hello
(initial-fact)
=>
(printout t "Hello World." crlf)
(bind ?groupNum (read))
)

(defrule rule1
        (groupNum ?groupNum)
        (test (>= ?groupNum 8000))
=>
(printout t "Test group. ")
)
