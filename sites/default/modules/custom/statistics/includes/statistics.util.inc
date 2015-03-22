<?php

define('total_match', 'Nubmer of Matches');
define('sum_loss', 'Number of LOSS');
define('total_win', 'Nubmer of WIN');
define('sum_draw', 'Number of DRAW');
define('BTTS_NO', 'Number of matches BTTS - NO');
define('BTTS_YES', 'Number of matches BTTS - YES');

define('UND_HALF','Number of matches played Under 1.5');
define('UND_2HALF','Number of matches played Under 2.5');
define('UND_3HALF','Number of matches played Under 3.5');

define('UP_HALF','Number of matches played Over 1.5');
define('UP_2HALF','Number of matches played Over 2.5');
define('UP_3HALF','Number of matches played Over 3.5');

define('AVRG_SCORED','Average Goal Scored');
define('AVRG_CONCERNED','Average Goals concerned');

define('BALL_POSS','Average Ball Possession');
define('BALL_POSS_OPP','Average Ball Possession (Opponents)');
define('BALL_ATTEMP_OPP','Average Goal Attempts');
define('AVRG_ATTEMP_CONCERNED', 'Average Goal Attempts (Concerned)');
define('AVRG_SHOTS','Average Shots on Goal');
define('AVRG_SHOTS_CONCERNED', 'Average Shots on Goal (Concerned)');
define('AVRG_CORNER','Average Corner Kicks');
define('AVRG_CORNERS_CONCERNED', 'Average Corner Kicks (Concerned)');
define('AVRG_OFFSIDE','Average Offsides');
define('AVRG_OFFSIDE_CONCERNED', 'Average Offsides (Opponents)');

define('AVRG_GOALKEEPER','Average Goalkeeper Saves');
define('AVRG_GOALKEEPER_OPP', 'Average Goalkeeper Saves (Opponents)');

define('AVRG_FOULS','Average Fouls');
define('AVRG_FOULS_OPP', 'Average Fouls (Opponents)');

define('AVRG_YC','Average Yellow Cards');
define('AVRG_YC_OPP', 'Average Yellow Cards (Opponents)');

define('AVRG_RC','Average Red Cards');
define('AVRG_RC_OPP', 'Average Red Cards (Opponents)');


function save_stat_uploaded_file($table, $form_state) {
	
	// Check to make sure that the file was uploaded to the server properly
 
  $uri = db_query("SELECT uri FROM {file_managed} WHERE fid = :fid", array(
    ':fid' => $form_state['input']['import']['fid'],
  ))->fetchField();
 
  if(!empty($uri)) {
    if(file_exists(drupal_realpath($uri))) { 
      // Open the csv
      $handle = fopen(drupal_realpath($uri), "r");
      // Go through each row in the csv and run a function on it. In this case we are parsing by '|' (pipe) characters.
      // If you want commas are any other character, replace the pipe with it.
      while (($data = fgetcsv($handle, 0, '|', '"')) !== FALSE) {
       $scv_data[] =$data;
      }
      fclose($handle);    
    }
   unset($scv_data[0]); // if csv files first row is title we dont need it;
   
   $newarray = array();
	
	foreach ($scv_data as $key => $value) {
		$newarray[$key] = explode(',',$value[0]);
	}
	unset($newarray[1]);
	//unset($newarray[2]);
	
if(!empty($newarray)){db_truncate($table)->execute();}
foreach ($newarray as $key=>$value){
	
	
	inserting($table, 
									$value[0],  
											$value[1],  
											$value[2],  
											$value[3].' '.$value[4],
											$value[5],  
											$value[6],  
											$value[7],  
											$value[8],  
											$value[9],  
											$value[10], 
											$value[11], 
											$value[12], 
											$value[13], 
											$value[14], 
											$value[15], 
											$value[16], 
										  $value[17], 
											$value[18], 
											$value[19], 
											$value[20], 
											$value[21], 
											$value[22], 
											$value[23], 
											$value[24],
											$value[25], 
											$value[26], 
											$value[27], 
											$value[28], 
											$value[29], 
											$value[30], 
											$value[31], 
											$value[32], 
											$value[33], 
											$value[34],
											$value[35]
										);
								}
								drupal_set_message(t("Soccer Scores Saved Successfully!"), 'status');
								}
}

function inserting($table,
  $country, 
  $league,   
  $round,
  $date,
  $home_team,
  $away_team,
  $ht_goals,
  $at_goals,
  $w1,
  $draw,
  $w2,
  $bh_possession,
  $ba_possession,
  $gh_attempts,
  $ga_attempts,
  $gh_shots,
  $ga_shots,
  $gh_shots_off,
  $ga_shots_off,
  $hb_shots,
  $ab_shots,
  $hc_kicks,
  $ac_kicks,
  $h_offsides,
  $a_offsides,
  $h_throw_in,
  $a_throw_in,
  $hgk_saves,
  $agk_saves,
  $h_fouls ,
  $a_fouls,
  $h_yc,
  $a_yc,
  $h_rc,
  $a_rc) {
 	
		db_insert($table)
	    ->fields(array(
				  'country'				=> $country, 
				  'league' 				=> $league,   
				  'round' 				=> $round,
				  'date' 					=> strtotime($date),
				  'home_team' 		=> $home_team,
				  'away_team' 		=> $away_team,
				  'ht_goals' 			=> $ht_goals,
				  'at_goals' 			=> $at_goals,
				  'w1' 						=> $w1,
				  'draw' 					=> $draw,
				  'w2' 						=> $w2,
				  'bh_possession' => $bh_possession,
				  'ba_possession' => $ba_possession,
				  'gh_attempts' 	=> $gh_attempts,
				  'ga_attempts' 	=> $ga_attempts,
				  'gh_shots' 			=> $gh_shots,
				  'ga_shots' 			=> $ga_shots,
				  'gh_shots_off' 	=> $gh_shots_off,
				  'ga_shots_off' 	=> $ga_shots_off,
				  'hb_shots' 			=> $hb_shots,
				  'ab_shots' 			=> $ab_shots,
				  'hc_kicks' 			=> $hc_kicks,
				  'ac_kicks' 			=> $ac_kicks,
				  'h_offsides' 		=> $h_offsides,
				  'a_offsides' 		=> $a_offsides,
				  'h_throw_in' 		=> $h_throw_in,
				  'a_throw_in' 		=> $a_throw_in,
				  'hgk_saves' 		=> $hgk_saves,
				  'agk_saves' 		=> $agk_saves,
				  'h_fouls' 			=> $h_fouls,
				  'a_fouls' 			=> $a_fouls,
				  'h_yc' 					=> $h_yc,
				  'a_yc' 					=> $a_yc,
				  'h_rc' 					=> $h_rc,
				  'a_rc' 					=> $a_rc,
			 ))->execute();
}


function get_stat_country() {
	$sql = db_query("SELECT country FROM statistics GROUP BY country")->fetchAll();

	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Country"; 
	
 foreach ($arr as $val) {
		$new_array[$val->country] = ucfirst(strtolower($val->country));
	
 }	
	return $new_array;
}

function get_stat_league($country) {

	$sql = db_query("SELECT league FROM statistics WHERE country='".$country."' GROUP BY league")->fetchAll();

	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select League"; 
	
 foreach ($arr as $val) {
		$new_array[$val->league] = ucfirst(strtolower($val->league));
 }	

	return $new_array;
}

function get_home_team($country, $league) {
	$sql = db_query("SELECT home_team FROM statistics WHERE country = '".$country."' AND league = '".$league."' ORDER BY home_team ASC")->fetchAll();
	
	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Team"; 
	
 foreach ($arr as $val) {
		$new_array[$val->home_team] = ucfirst(strtolower($val->home_team));
 }	

	return $new_array;
}

function get_away_team($country, $league) {
	$sql = db_query("SELECT away_team FROM statistics WHERE country = '".$country."' AND league = '".$league."'ORDER BY away_team ASC")->fetchAll();
	
	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Team"; 
	
 foreach ($arr as $val) {
		$new_array[$val->away_team] = ucfirst(strtolower($val->away_team));
 }	
	return $new_array;
}

function get_full_stat($league, $stat_type) {
	//$stat_type = '';
	$sql = db_query("SELECT 
totalcount_match AS total_match,
totalcount_home_win + totalcount_away_win AS total_win,
totalcount_home_drow AS sum_draw,
(totalcount_match - (totalcount_home_drow + (totalcount_home_win + totalcount_away_win))) AS sum_loss,
totalcount_home_btts_yes AS BTTS_YES,
totalcount_match - totalcount_home_btts_yes AS BTTS_NO,

ROUND((totalcount_home_gols_arvg + totalcount_away_gols_arvg) / totalcount_match, 2) AS AVRG_SCORED,
ROUND((totalcount_away_gols_conc_arvg + totalcount_home_gols_conc_arvg) / totalcount_match, 2) AS AVRG_CONCERNED,
totalcount_away_und_half AS UND_HALF,
totalcount_home_up_half  AS UP_HALF,
totalcount_home_und_2half  AS UND_2HALF,
totalcount_home_up_2half  AS UP_2HALF,
totalcount_home_und_3half AS UND_3HALF,
totalcount_home_up_3half AS UP_3HALF,

CONCAT(ROUND((ht_possession.pos_sum + at_possession.pos_sum) / totalcount_match, 2),'%') AS BALL_POSS,
CONCAT(ROUND((htop_possession.pos_sum + atop_possession.pos_sum) / totalcount_match, 2),'%') AS BALL_POSS_OPP,
ROUND((at_gols_attarvg.gols_sum + ht_gols_attarvg.gols_sum) / totalcount_match,2) AS BALL_ATTEMP_OPP,
ROUND((at_gols_conc_attarvg.gols_sum + ht_gols_conc_attarvg.gols_sum) / totalcount_match,2) AS AVRG_ATTEMP_CONCERNED,
ROUND((at_gols_shotsavrg.gols_sum + ht_gols_shotsavrg.gols_sum) / totalcount_match,2) AS AVRG_SHOTS,
ROUND((at_gols_shots_concavrg.gols_sum + ht_gols_shots_concavrg.gols_sum) / totalcount_match,2) AS AVRG_SHOTS_CONCERNED,

ROUND((at_corner_avrg.gols_sum + ht_corner_avrg.gols_sum) / totalcount_match,2) AS AVRG_CORNER,
ROUND((at_corner_conc_avrg.gols_sum + ht_corner_conc_avrg.gols_sum) / totalcount_match,2) AS AVRG_CORNERS_CONCERNED,

ROUND((at_offsides_avrg.gols_sum + ht_offsides_avrg.gols_sum) / totalcount_match,2) AS AVRG_OFFSIDE,
ROUND((at_offsides_conc_avrg.gols_sum + ht_offsides_conc_avrg.gols_sum) / totalcount_match,2) AS AVRG_OFFSIDE_CONCERNED,

ROUND((at_goalkieper_avrg.gols_sum + ht_goalkieper_avrg.gols_sum) / totalcount_match,2) AS AVRG_GOALKEEPER,
ROUND((at_goalkieper_opp_avrg.gols_sum + ht_goalkieper_opp_avrg.gols_sum) / totalcount_match,2) AS AVRG_GOALKEEPER_OPP,

ROUND((at_fouls_avrg.gols_sum + ht_fouls_avrg.gols_sum) / totalcount_match,2) AS AVRG_FOULS,
ROUND((at_fouls_opp_avrg.gols_sum + ht_fouls_opp_avrg.gols_sum) / totalcount_match,2) AS AVRG_FOULS_OPP,

ROUND((at_yc_avrg.gols_sum + ht_yc_avrg.gols_sum) / totalcount_match,2) AS AVRG_YC,
ROUND((at_yc_opp_avrg.gols_sum + ht_yc_opp_avrg.gols_sum) / totalcount_match,2) AS AVRG_YC_OPP,

ROUND((at_rc_avrg.gols_sum + ht_rc_avrg.gols_sum) / totalcount_match,2) AS AVRG_RC,
ROUND((at_rc_opp_avrg.gols_sum + ht_rc_opp_avrg.gols_sum) / totalcount_match,2) AS AVRG_RC_OPP

		FROM 
		
 (SELECT count(*) AS totalcount_away_win FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s
    WHERE ht_goals < at_goals AND away_team = '".$league."') AS away,
		
 (SELECT count(*) AS totalcount_home_win FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals > at_goals AND home_team = '".$league."') AS home,
		
(SELECT count(*) AS totalcount_match FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s ) AS total_match,
		
 (SELECT count(*) AS totalcount_home_drow FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals = at_goals) AS homedrow,
		
/*
 (SELECT count(*) AS totalcount_away_drow FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE at_goals = ht_goals) AS awaydrow,
*/
		
  (SELECT count(*) AS totalcount_home_btts_yes FROM 
   (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals > 0 AND at_goals > 0) AS homebtts_yes,
 
/*
  (SELECT count(*) AS totalcount_away_btts_yes FROM 
   (SELECT * FROM statistics WHERE home_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals > 0 AND at_goals > 0) AS awaybtts_yes,
*/
 
/* UNDER 1.5 */
    (SELECT count(*) AS totalcount_away_und_half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 1) AS away_und_half,

/*
    (SELECT count(*) AS totalcount_home_und_half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 1) AS home_und_half,
*/
/* UNDER 2.5 */
    (SELECT count(*) AS totalcount_home_und_2half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 2) AS home_und_2half,
		
/*
    (SELECT count(*) AS totalcount_away_und_2half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 2) AS away_und_2half,
*/
		
/* UNDER 3.5 */
    (SELECT count(*) AS totalcount_home_und_3half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 3) AS home_und_3half,
		
/*
    (SELECT count(*) AS totalcount_away_und_3half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 3) AS away_und_3half,
*/
/* UP 1.5 */
    (SELECT count(*) AS totalcount_home_up_half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 2) AS home_up_half,
		
		
/*
    (SELECT count(*) AS totalcount_away_up_half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 2) AS away_up_half,
*/
/* UP 2.5 */
    (SELECT count(*) AS totalcount_home_up_2half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 3) AS home_up_2half,
		
/*
    (SELECT count(*) AS totalcount_away_up_2half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 3) AS away_up_2half,
*/
/* UP 3.5 */
    (SELECT count(*) AS totalcount_home_up_3half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 4) AS home_up_3half,
		
/*
    (SELECT count(*) AS totalcount_away_up_3half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 4) AS away_up_3half,
*/
		
/* ARVG GOLS SCORED */
   (SELECT IFNULL(sum(ht_goals),0) AS totalcount_home_gols_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE ht_goals  > 0 AND home_team = '".$league."') AS home_gols_arvg,
   	 
   (SELECT IFNULL(sum(at_goals),0) AS totalcount_away_gols_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE at_goals  > 0 AND away_team = '".$league."') AS away_gols_arvg,
   	 
/* ARVG GOLS CONCERNED	 */
   (SELECT IFNULL(sum(at_goals),0) AS totalcount_home_gols_conc_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE at_goals  > 0 AND home_team = '".$league."') AS home_gols_conc_arvg,
		
   (SELECT IFNULL(sum(ht_goals),0) AS totalcount_away_gols_conc_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE ht_goals  > 0 AND away_team = '".$league."') AS away_gols_conc_arvg,	
			
/* ARVG Ball Possession */	
	 (SELECT IFNULL(REPLACE(sum(bh_possession),'%',''),0) AS pos_sum FROM
    (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_possession,
		
	 (SELECT IFNULL(REPLACE(sum(ba_possession),'%',''),0) AS pos_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_possession,		
		
/* ARVG Ball Possession (Opponents) */	
	(SELECT IFNULL(REPLACE(sum(ba_possession),'%',''),0) AS pos_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS htop_possession,
		
	 (SELECT IFNULL(REPLACE(sum(bh_possession),'%',''),0) AS pos_sum FROM
	  (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS atop_possession,
		
/* ARVG GOLS ATTEMPTS */
	  (SELECT IFNULL(sum(ga_attempts),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_gols_attarvg,
	
	   (SELECT IFNULL(sum(gh_attempts),0) AS gols_sum FROM
		 (SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_gols_attarvg,
		
/* ARVG GOLS ATTEMPTS CONCERNED */
	 (SELECT IFNULL(sum(ga_attempts),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_gols_conc_attarvg,
	
	  (SELECT IFNULL(sum(gh_attempts),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_gols_conc_attarvg,
		
/* ARVG GOLS SHOTS */
	  (SELECT IFNULL(sum(ga_shots),0) AS gols_sum FROM 
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		 WHERE away_team = '".$league."') AS at_gols_shotsavrg,
	
	  (SELECT IFNULL(sum(gh_shots),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_gols_shotsavrg,
		
/* ARVG GOLS SHOTS CONCERNED */
	  (SELECT IFNULL(sum(ga_shots),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_gols_shots_concavrg,
	
	  (SELECT IFNULL(sum(gh_shots),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_gols_shots_concavrg,
			
/* ARVG CORNER KICKS */
	  (SELECT IFNULL(sum(ac_kicks),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_corner_avrg,
	
	  (SELECT IFNULL(sum(hc_kicks),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		 WHERE home_team = '".$league."') AS ht_corner_avrg,
		
/* ARVG CORNER KICKS CONCERNED */
	  (SELECT IFNULL(sum(ac_kicks),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_corner_conc_avrg,
	
	  (SELECT IFNULL(sum(hc_kicks),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_corner_conc_avrg,		

/* ARVG OFFSIDES */
	  (SELECT IFNULL(sum(a_offsides),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_offsides_avrg,
	
		(SELECT IFNULL(sum(h_offsides),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_offsides_avrg,
		
/* ARVG OFFSIDES CONCERNED */
		(SELECT IFNULL(sum(a_offsides),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_offsides_conc_avrg,
	
		(SELECT IFNULL(sum(h_offsides),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_offsides_conc_avrg,
		
/* ARVG Goalkeeper */
		(SELECT IFNULL(sum(agk_saves),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) as s
		WHERE away_team = '".$league."') AS at_goalkieper_avrg,
	
		(SELECT IFNULL(sum(hgk_saves),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_goalkieper_avrg,
		
/* ARVG Goalkeeper Opponents */
		(SELECT IFNULL(sum(agk_saves),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type)AS s
		WHERE home_team = '".$league."') AS at_goalkieper_opp_avrg,
	
		(SELECT IFNULL(sum(hgk_saves),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_goalkieper_opp_avrg,
/* ARVG FOULS */
		(SELECT IFNULL(sum(a_fouls),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_fouls_avrg,
	
		(SELECT IFNULL(sum(h_fouls),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_fouls_avrg,
		
/* ARVG FOULS Opponents */
		(SELECT IFNULL(sum(a_fouls),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_fouls_opp_avrg,
	
		(SELECT IFNULL(sum(h_fouls),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_fouls_opp_avrg,
		
/* ARVG YC */
		(SELECT IFNULL(sum(a_yc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		 ORDER BY DATE DESC $stat_type) AS s
		 WHERE away_team = '".$league."') AS at_yc_avrg,
	
		(SELECT IFNULL(sum(h_yc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		 ORDER BY DATE DESC $stat_type) AS s
		 WHERE home_team = '".$league."') AS ht_yc_avrg,
		
/* ARVG YC Opponents */
		(SELECT IFNULL(sum(a_yc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS at_yc_opp_avrg,
	
		(SELECT IFNULL(sum(h_yc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS ht_yc_opp_avrg,

/* ARVG RC */
		(SELECT IFNULL(sum(a_rc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE away_team = '".$league."') AS at_rc_avrg,
	
		(SELECT IFNULL(sum(h_rc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."') AS ht_rc_avrg,
		
/* ARVG RC Opponents */
	 (SELECT IFNULL(sum(a_rc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE home_team = '".$league."')AS at_rc_opp_avrg,
	
	 (SELECT IFNULL(sum(h_rc),0) AS gols_sum FROM
		(SELECT * FROM statistics WHERE home_team = '".$league."' OR away_team = '".$league."'
		 ORDER BY DATE DESC $stat_type) AS s
		 WHERE away_team = '".$league."') AS ht_rc_opp_avrg")->fetchAll();
									
return $sql;
}


function get_home_stat($league, $stat_type) {
	
	$sql = db_query("SELECT 
totalcount_match AS total_match,
totalcount_home_win AS total_win,
totalcount_home_drow AS sum_draw,
(totalcount_match - (totalcount_home_drow + totalcount_home_win)) AS sum_loss,
totalcount_home_btts_yes AS BTTS_YES,
totalcount_match - totalcount_home_btts_yes AS BTTS_NO,
ROUND(totalcount_home_gols_arvg / totalcount_match,2) AS AVRG_SCORED,
ROUND(totalcount_home_gols_conc_arvg / totalcount_match,2) AS AVRG_CONCERNED,

totalcount_home_und_half AS UND_HALF,
totalcount_home_up_half AS UP_HALF,

totalcount_home_und_2half AS UND_2HALF,
totalcount_home_up_2half AS UP_2HALF,

totalcount_home_und_3half AS UND_3HALF,
totalcount_home_up_3half AS UP_3HALF,

CONCAT(ROUND(ht_possession.pos_sum / totalcount_match,2),'%') AS BALL_POSS,
CONCAT(ROUND(htop_possession.pos_sum / totalcount_match,2),'%') AS BALL_POSS_OPP,
ROUND(ht_gols_attarvg.gols_sum / totalcount_match,2) AS BALL_ATTEMP_OPP,
ROUND(ht_gols_conc_attarvg.gols_sum / totalcount_match,2) AS AVRG_ATTEMP_CONCERNED,
ROUND(ht_gols_shotsavrg.gols_sum / totalcount_match,2) AS AVRG_SHOTS,
ROUND(ht_gols_shots_concavrg.gols_sum / totalcount_match,2) AS AVRG_SHOTS_CONCERNED,

ROUND(ht_corner_avrg.gols_sum / totalcount_match,2) AS AVRG_CORNER,
ROUND(ht_corner_conc_avrg.gols_sum / totalcount_match,2) AS AVRG_CORNERS_CONCERNED,

ROUND(ht_offsides_avrg.gols_sum / totalcount_match,2) AS AVRG_OFFSIDE,
ROUND(ht_offsides_conc_avrg.gols_sum / totalcount_match,2) AS AVRG_OFFSIDE_CONCERNED,

ROUND(ht_goalkieper_avrg.gols_sum / totalcount_match,2) AS AVRG_GOALKEEPER,
ROUND(ht_goalkieper_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_GOALKEEPER_OPP,

ROUND(ht_fouls_avrg.gols_sum / totalcount_match,2) AS AVRG_FOULS,
ROUND(ht_fouls_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_FOULS_OPP,

ROUND(ht_yc_avrg.gols_sum / totalcount_match,2) AS AVRG_YC,
ROUND(ht_yc_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_YC_OPP,

ROUND(ht_rc_avrg.gols_sum / totalcount_match,2) AS AVRG_RC,
ROUND(ht_rc_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_RC_OPP

FROM

 (SELECT count(*) AS totalcount_match FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s ) AS total_match,

 (SELECT count(*) AS totalcount_home_drow FROM 
  (SELECT * FROM statistics WHERE home_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals = at_goals) AS drow,
 
	 (SELECT count(*) AS totalcount_home_win FROM 
	  (SELECT * FROM statistics WHERE home_team = '".$league."' 
	 	ORDER BY DATE DESC $stat_type) AS s
	 WHERE ht_goals > at_goals) AS home,
 
  (SELECT count(*) AS totalcount_home_btts_yes FROM 
   (SELECT * FROM statistics WHERE home_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals > 0 AND at_goals > 0) AS btts_yes,
/* UNDER 1.5 */ 
    (SELECT count(*) AS totalcount_home_und_half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 1) AS home_und_half,
/* UNDER 2.5 */ 
    (SELECT count(*) AS totalcount_home_und_2half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 2) AS home_und_2half,
/* UNDER 3.5 */ 
    (SELECT count(*) AS totalcount_home_und_3half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 3) AS home_und_3half,
/* UP 1.5 */ 
    (SELECT count(*) AS totalcount_home_up_half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 2) AS home_up_half,
/* UP 2.5 */ 
    (SELECT count(*) AS totalcount_home_up_2half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 3) AS home_up_2half,
/* UP 3.5 */ 
    (SELECT count(*) AS totalcount_home_up_3half FROM 
 	  (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 4) AS home_up_3half,
/* ARVG GOLS SCORED */
   (SELECT sum(ht_goals) AS totalcount_home_gols_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE ht_goals  > 0 ) home_gols_arvg,
/* ARVG GOLS SCORED */
   (SELECT sum(at_goals) AS totalcount_home_gols_conc_arvg FROM
   	(SELECT * FROM statistics WHERE home_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE at_goals  > 0 ) home_gols_conc_arvg,	
/* ARVG Ball Possession */
	  (SELECT REPLACE(sum(bh_possession),'%','') AS pos_sum 
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."' 
		ORDER BY DATE DESC $stat_type) AS s) AS ht_possession,
/* ARVG Ball Possession (Opponents) */	
		(SELECT REPLACE(sum(ba_possession),'%','') AS pos_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS htop_possession,

		
/* ARVG GOLS ATTEMPTS */
	
		(SELECT sum(gh_attempts) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_attarvg,
		
/* ARVG GOLS ATTEMPTS CONCERNED */
		(SELECT sum(ga_attempts) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_conc_attarvg,

		
/* ARVG GOLS SHOTS */
		(SELECT sum(gh_shots) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_shotsavrg,
		
/* ARVG GOLS SHOTS CONCERNED */
		(SELECT sum(ga_shots) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_shots_concavrg,

			
/* ARVG CORNER KICKS */
	
		(SELECT sum(hc_kicks) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_corner_avrg,
		
/* ARVG CORNER KICKS CONCERNED */
		(SELECT sum(ac_kicks) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_corner_conc_avrg,

/* ARVG OFFSIDES */
	
		(SELECT sum(h_offsides) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_offsides_avrg,
		
/* ARVG OFFSIDES CONCERNED */
		(SELECT sum(a_offsides) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_offsides_conc_avrg,
		
/* ARVG Goalkeeper */
		(SELECT sum(hgk_saves) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_goalkieper_avrg,
		
/* ARVG Goalkeeper Opponents */
		(SELECT sum(agk_saves) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_goalkieper_opp_avrg,
	
/* ARVG FOULS */
	
		(SELECT sum(h_fouls) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_fouls_avrg,
		
/* ARVG FOULS Opponents */
		(SELECT sum(a_fouls) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_fouls_opp_avrg,
		
/* ARVG YC */
	
		(SELECT sum(h_yc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_yc_avrg,
		
/* ARVG YC Opponents */
		(SELECT sum(a_yc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_yc_opp_avrg,
	
/* ARVG RC */
		(SELECT sum(h_rc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_rc_avrg,
		
/* ARVG RC Opponents */
		(SELECT sum(a_rc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE home_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_rc_opp_avrg")->fetchAll();
									
return $sql;
}

function get_away_stat($league, $stat_type) {
	
	$sql = db_query("SELECT 
totalcount_match AS total_match,
totalcount_home_drow AS sum_draw,
totalcount_home_win AS total_win,
(totalcount_match - (totalcount_home_drow + totalcount_home_win)) AS sum_loss,
totalcount_home_btts_yes AS BTTS_YES,
totalcount_match - totalcount_home_btts_yes AS BTTS_NO,
ROUND(totalcount_home_gols_arvg / totalcount_match,2) AS AVRG_SCORED,
ROUND(totalcount_home_gols_conc_arvg / totalcount_match,2) AS AVRG_CONCERNED,

totalcount_home_und_half AS UND_HALF,
totalcount_home_up_half AS UP_HALF,

totalcount_home_und_2half AS UND_2HALF,
totalcount_home_up_2half AS UP_2HALF,

totalcount_home_und_3half AS UND_3HALF,
totalcount_home_up_3half AS UP_3HALF,

CONCAT(ROUND(ht_possession.pos_sum / totalcount_match,2),'%') AS BALL_POSS,
CONCAT(ROUND(htop_possession.pos_sum / totalcount_match,2),'%') AS BALL_POSS_OPP,
ROUND(ht_gols_attarvg.gols_sum / totalcount_match,2) AS BALL_ATTEMP_OPP,
ROUND(ht_gols_conc_attarvg.gols_sum / totalcount_match,2) AS AVRG_ATTEMP_CONCERNED,
ROUND(ht_gols_shotsavrg.gols_sum / totalcount_match,2) AS AVRG_SHOTS,
ROUND(ht_gols_shots_concavrg.gols_sum / totalcount_match,2) AS AVRG_SHOTS_CONCERNED,

ROUND(ht_corner_avrg.gols_sum / totalcount_match,2) AS AVRG_CORNER,
ROUND(ht_corner_conc_avrg.gols_sum / totalcount_match,2) AS AVRG_CORNERS_CONCERNED,

ROUND(ht_offsides_avrg.gols_sum / totalcount_match,2) AS AVRG_OFFSIDE,
ROUND(ht_offsides_conc_avrg.gols_sum / totalcount_match,2) AS AVRG_OFFSIDE_CONCERNED,

ROUND(ht_goalkieper_avrg.gols_sum / totalcount_match,2) AS AVRG_GOALKEEPER,
ROUND(ht_goalkieper_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_GOALKEEPER_OPP,

ROUND(ht_fouls_avrg.gols_sum / totalcount_match,2) AS AVRG_FOULS,
ROUND(ht_fouls_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_FOULS_OPP,

ROUND(ht_yc_avrg.gols_sum / totalcount_match,2) AS AVRG_YC,
ROUND(ht_yc_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_YC_OPP,

ROUND(ht_rc_avrg.gols_sum / totalcount_match,2) AS AVRG_RC,
ROUND(ht_rc_opp_avrg.gols_sum / totalcount_match,2) AS AVRG_RC_OPP



FROM

 (SELECT count(*) AS totalcount_match FROM 
  (SELECT * FROM statistics WHERE away_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s ) AS total_match,

 (SELECT count(*) AS totalcount_home_drow FROM 
  (SELECT * FROM statistics WHERE away_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals = at_goals) AS drow,
 
 (SELECT count(*) AS totalcount_home_win FROM 
  (SELECT * FROM statistics WHERE away_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE at_goals > ht_goals) AS home,
 
  (SELECT count(*) AS totalcount_home_btts_yes FROM 
   (SELECT * FROM statistics WHERE away_team = '".$league."' 
 	ORDER BY DATE DESC $stat_type) AS s
 WHERE ht_goals > 0 AND at_goals > 0) AS btts_yes,
/* UNDER 1.5 */ 
    (SELECT count(*) AS totalcount_home_und_half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 1) AS home_und_half,
/* UNDER 2.5 */ 
    (SELECT count(*) AS totalcount_home_und_2half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 2) AS home_und_2half,
/* UNDER 3.5 */ 
    (SELECT count(*) AS totalcount_home_und_3half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals <= 3) AS home_und_3half,
/* UP 1.5 */ 
    (SELECT count(*) AS totalcount_home_up_half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 2) AS home_up_half,
/* UP 2.5 */ 
    (SELECT count(*) AS totalcount_home_up_2half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 3) AS home_up_2half,
/* UP 3.5 */ 
    (SELECT count(*) AS totalcount_home_up_3half FROM 
 	  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s
		WHERE ht_goals + at_goals >= 4) AS home_up_3half,
/* ARVG GOLS SCORED */
   (SELECT sum(at_goals) AS totalcount_home_gols_arvg FROM
   	(SELECT * FROM statistics WHERE away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE at_goals  > 0 ) home_gols_arvg,
/* ARVG GOLS CONCERNED */
   (SELECT sum(ht_goals) AS totalcount_home_gols_conc_arvg FROM
   	(SELECT * FROM statistics WHERE away_team = '".$league."'
   	 ORDER BY DATE DESC $stat_type) AS s
   	 WHERE ht_goals  > 0 ) home_gols_conc_arvg,	
/* ARVG Ball Possession */
	  (SELECT REPLACE(sum(ba_possession),'%','') AS pos_sum FROM
		(SELECT * FROM statistics WHERE away_team = '".$league."' 
		ORDER BY DATE DESC $stat_type) AS s) AS ht_possession,
/* ARVG Ball Possession (Opponents) */	
	  (SELECT REPLACE(sum(bh_possession),'%','') AS pos_sum FROM 
		(SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS htop_possession,

		
/* ARVG GOLS ATTEMPTS */
	
		(SELECT sum(ga_attempts) AS gols_sum FROM
		(SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_attarvg,
		
/* ARVG GOLS ATTEMPTS CONCERNED */
		(SELECT sum(gh_attempts) AS gols_sum FROM 
		(SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_conc_attarvg,

		
/* ARVG GOLS SHOTS */
		(SELECT sum(ga_shots) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_shotsavrg,
		
/* ARVG GOLS SHOTS CONCERNED */
		(SELECT sum(gh_shots) AS gols_sum FROM 
		(SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_gols_shots_concavrg,

			
/* ARVG CORNER KICKS */
	
		(SELECT sum(ac_kicks) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_corner_avrg,
		
/* ARVG CORNER KICKS CONCERNED */
		(SELECT sum(hc_kicks) AS gols_sum
		FROM  (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_corner_conc_avrg,

/* ARVG OFFSIDES */
	
		(SELECT sum(a_offsides) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_offsides_avrg,
		
/* ARVG OFFSIDES CONCERNED */
		(SELECT sum(h_offsides) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_offsides_conc_avrg,
		
/* ARVG Goalkeeper */
		(SELECT sum(agk_saves) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_goalkieper_avrg,
		
/* ARVG Goalkeeper Opponents */
		(SELECT sum(hgk_saves) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_goalkieper_opp_avrg,
	
/* ARVG FOULS */
	
		(SELECT sum(a_fouls) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_fouls_avrg,
		
/* ARVG FOULS Opponents */
		(SELECT sum(h_fouls) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_fouls_opp_avrg,
		
/* ARVG YC */
	
		(SELECT sum(a_yc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_yc_avrg,
		
/* ARVG YC Opponents */
		(SELECT sum(h_yc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_yc_opp_avrg,
	
/* ARVG RC */
		(SELECT sum(a_rc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_rc_avrg,
		
/* ARVG RC Opponents */
		(SELECT sum(h_rc) AS gols_sum
		FROM (SELECT * FROM statistics WHERE away_team = '".$league."'
		ORDER BY DATE DESC $stat_type) AS s) AS ht_rc_opp_avrg")->fetchAll();
									
return $sql;
}

function build_array($home, $away) {
	$array = array();
	
  foreach($home[0] as $key => $val) {
	  $array[$key]         = $val.'_'.$away[0]->$key;
  }
	
	return $array;
}

function get_match_numbers($league) {
	
	$sql = db_query("SELECT count(*) AS TOTAL FROM statistics WHERE home_team = '".$league."'")->fetchAll();
	
	return $sql;
}

function build_filter($team) {
	$total_match = get_match_numbers($team);
	$total_match = $total_match[0]->TOTAL;
	if ($total_match > 10) {
		$total_match = 10;
	}
	$array       = array();
	
for ($x = 0; $x <= $total_match; $x++) {
		$array[-1] = 'Select Last Matches';
		$array[0] = 'Select Full Data';
    $array[$x] = $x;
} 

	return $array;
	
}

function get_left_class_color($home, $away) {
$class = 'tb-chart-left';
if ($home > $away) {
	$class = 'tb-chart-left';
}

if ($home < $away) {
	$class = 'tb-chart-left-less';
}

if ($home == $away) {
	$class = 'tb-chart-left-eq';
}

return $class;
}

function get_right_class_color($home, $away) {
$class = 'tb-chart-right';
if ($home < $away) {
	$class = 'tb-chart-right';
}

if ($home > $away) {
	$class = 'tb-chart-right-less';
}

if ($home == $away) {
	$class = 'tb-chart-right-eq';
}

return $class;
}
