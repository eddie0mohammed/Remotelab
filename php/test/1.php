#!/usr/bin/php
<?php

function my_add($p1, $p2)
{
	return $p1 + $p2;
}


$num = 42;
$my_str = "Hello";
//$my_tab = array("zero", "one", "", "four");
$my_hash = array("key1" => "val1", "key2" => "val2");

$my_tab = explode(";", "zero;un;deux;trois");

//echo $my_str."\n".$num."\n";

//echo $my_tab[1]."\n";
//echo $my_hash["key1"];


//echo "$my_tab\n\n";

//print_r($my_tab);

//echo my_add("10", "12")."\n";

// if ($my_tab[0] == "zeros")
// echo "ok\n";
// else
// 	echo "ko\n";

// echo $argc."\n";
// print_r($argv);

// print_r($my_tab);

// foreach ($my_tab as $elem)
// {
// 	echo $elem."\n";
// }


// $name = "mo";
// $str1 = "hammed";

// echo $name." ".$str1."\n";

// $val1 = 42;

// $calculation = $val1 / 2 + 10 - 1;

// echo "The result of the calculation is: ".$calculation."\n";


// $name = "eddie";
// $varname = "name";

// echo $$varname."\n";


// $my_array = array("tom", "jo", "eddie", 1);

// $my_array[1] = "mo";

// $my_array[] = 2;
// print_r($my_array);

// // foreach($my_array as $elem)
// // {
// // 	echo ($elem."\n");
// // }

// $my_arr[] = "hello";
// $my_arr[] = "good";
// $my_arr[5] = "heyyy";
// $my_arr["password"] = "12345";

// print_r($my_arr);

// foreach($my_arr as $elem)
// {
// 	echo ($elem."\n");
// }

// $my_arr = array(
// "france" => "french",
// "Usa" => "english",
// "mauritius" => "creole"
// );


// $my_arr["status"] = "kool";
// print_r($my_arr);

// echo sizeof($my_arr)."\n";


// unset($my_arr["france"]);

// print_r($my_arr);

$family = array("rob", "chris", "eddie", "sarah", "joe");

// for ($i = 0; $i < 3; $i++)
// {
// 	echo $family[$i]."\n";
// }

// $i = 0;
// while ($i < sizeof($family))
// {
// 	echo $family[$i]."\n";
// 	$i++;
// }


// foreach ($family as $index => $elem)
// {
// 	$elem = $elem." edun";
// 	echo "index ".$index." contains: ".$elem."\n";
// }


$i = 0;

while ($i < sizeof($family))
{
	echo $family[$i]."\n";
	$i++;
}

print_r($_GET);























?>
