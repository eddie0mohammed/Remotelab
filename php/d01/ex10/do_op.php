#!/usr/bin/php
<?php

if ($argc == 4)
{
	$num1 = trim($argv[1]);
	$operator = trim($argv[2]);
	$num2 = trim($argv[3]);

	if ($operator == "+")
		$res = $num1 + $num2;
	else if ($operator == "-")
		$res = $num1 - $num2;
	else if ($operator == "/")
		$res = $num1 / $num2;
	else if ($operator == "%")
		$res = $num1 % $num2;
	else if ($operator == "*")
		$res = $num1 * $num2;
	print($res)."\n";

}
else
{
	print("Incorrect Parameters\n");
}

?>