#!/usr/bin/php
<?php

if ($argc > 1)
{
	$i = 1;
	$arr = array();
	while ($i < $argc)
	{
		$ret = explode(" ", $argv[$i]);
		$ret = array_filter($ret);
		$ret = array_slice($ret, 0);
		$i++;
		$arr = array_merge($arr, $ret);
	}
	$alphabets = array();
	$numeric = array();
	$else = array();

	foreach ($arr as $value)
	{
		if (ctype_alpha($value))
			$alphabets[] = $value;
		else if (ctype_alnum($value))
			$numeric[] = $value;
		else
			$else[] = $value; 
	}

	natcasesort($alphabets);
	natcasesort($numeric);
	natcasesort($else);

	foreach ($alphabets as $value)
	{
		print($value)."\n";
	}
	foreach ($numeric as $value)
	{
		print($value)."\n";
	}
	foreach ($else as $value)
	{
		print($value)."\n";
	}
}

?>