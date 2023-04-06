<?php

	echo "Choose rock, paper, or scissors: ";
	$player = trim(fgets(STDIN));
	$computer = rand(1,3);
	if ($player == "rock")
	{
		if ($computer == 1)
		{
			echo "Draw, try again. The computer chose rock.\n";
		}
		else if ($computer == 2)
		{
			echo "Sorry, you lost. The computer chose paper.\n";
		}
		else if ($computer == 3)
		{
			echo "Congratulations! You won! The computer chose scissors.\n";
		}
	}
	else if ($player == "paper")
	{
		if ($computer == 1)
		{
			echo "Congratulations! You won! The computer chose rock.\n";
		}
		else if ($computer == 2)
		{
			echo "Draw, try again. The computer chose paper.\n";
		}
		else if ($computer == 3)
		{
			echo "Sorry, you lost. The computer chose scissors.\n";
		}
	}
	else if ($player == "scissors")
	{
		if ($computer == 1)
		{
			echo "Sorry, you lost. The computer chose rock.\n";
		}
		else if ($computer == 2)
		{
			echo "Congratulations! You won! The computer chose paper.\n";
		}
		else if ($computer == 3)
		{
			echo "Draw, try again. The computer chose scissors.\n";
		}
	}
	else
	{
		echo "Sorry, you lost. Your spelling sucks, be better next time.\n";
	}
?>
