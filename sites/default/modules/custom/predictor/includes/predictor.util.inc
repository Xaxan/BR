<?php

function insert_final_record($table, $date, $time, $iso, $country, $competition, $home_team, $away_team, $w1, $draw, $W2, $prr, $pro, $prr_yc, $pro_co, $result, $bts, $goals_ou, $yellow_cards_ou, $corner_ou, $home_team_score, $away_team_score, $yellow_cards, $corner, $yc_vip, $vip) {
 	
		db_insert('predictor_'.$table)
    ->fields(array(
					'date'            => strtotime($date),
					'time'            => $time, 
					'iso'             => $iso, 
					'country'         => $country,
					'competition'     => $competition, 
					'home_team'       => $home_team, 
					'away_team'       => $away_team, 
					'w1'              => $w1, 
					'draw'            => $draw, 
					'w2'              => $W2,
					'prr'             => $prr, 
					'pro'             => $pro,
					'prr_yc'          => $prr_yc,
					'prr_cor'         => $pro_co,
					'result'          => $result, 
					'bts' 			      => $bts, 
					'goals_ou'        => $goals_ou,
					'yellow_cards_ou' => $yellow_cards_ou,
					'corners_ou'      => $corner_ou, 
					'home_team_score' => $home_team_score,
					'away_team_score' => $away_team_score, 
					'yellow_cards'    => $yellow_cards,
					'corner'          => $corner,
					'yc_vip'          => $yc_vip,
					'vip'             => $vip,
					))->execute();
}

function save_uploaded_file($table, $form_state) {
	
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
	
if(!empty($newarray)){db_truncate('predictor_'.$table)->execute();}
foreach ($newarray as $key=>$value){

	insert_final_record($table, $value[0],  //date
											$value[1],  //time
											$value[2],  //iso
											$value[3],  //country
											$value[4],  //competition
											$value[5],  //home_team
											$value[6],  //away_team
											$value[7],  //W1
											$value[8],  //DRAW
											$value[9],  //W2
											$value[10], //prr 
											$value[11], //pro
											$value[12], //prr_yc
											$value[13], //pro_cor
											$value[14], //results
											$value[15], // bts
											$value[16], //goals_ou
										  $value[17], //yellow_cards_ou
											$value[18], //corner_ou
											$value[19], //home_team_score
											$value[20], //away_team_score
											$value[21], //yellow_cards
											$value[22], //corner
											$value[23], //yc_vip
											$value[24] //vip
										);
								}
								drupal_set_message(t("Soccer Scores Saved Successfully!"), 'status');
								}
}


function insert_leagule_archive(){
	
	   $query = "INSERT INTO {predictor_league_archive} SELECT * FROM {predictor_league}";
		 db_query($query);
}

function insert_yc_archive(){
	
	   $query = "INSERT INTO {predictor_corners_archive} SELECT * FROM {predictor_corners}";
		 db_query($query);
}


function result_data_render_rules($data, $vip, $home, $away) {
  global $user;
	$result = $data;
	
	if ($vip == 'VIPU' && !user_has_role('member1X2')) {
		$result = array('data' =>'VIP','style' => array('background-color:#0a4805;border-right-color:#0a4805;color:white;'.get_3d_bgcolor(0)));
	}elseif ($vip != 'VIP'  && ($home !='na' || $away !='na')/* 0 means emppty score*/) {
 		$result = get_result_color($data, $home, $away);
 	}

	return $result;
}

function bts_data_render_rules($data, $vip, $home, $away) {
  global $user;
	$result = $data;
	
	if ($vip == 'VIPU' && !user_has_role('member1X2')) {
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif ($vip != 'VIP' && ($home !='na' || $away !='na')) {
 		$result = get_bts_color($data, $home, $away);
 	}

	return $result;
}

function goals_ou_data_render_rules($data, $vip, $home, $away) {
  global $user;
	$result = $data;
	
	if ($vip == 'VIPU' && !user_has_role('member1X2')) {
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif ($vip != 'VIP' && ($home !='na' || $away !='na')) {
 		$result = get_goals_ou_color($data, $home, $away);
 	}

	return $result;
}

function data_render_rules_yellow_cards_ou($data, $vip, $yellow_cards, $type = NULL, $prr = NULL, $arg = NULL) {
  global $user;
	$result = $data;

	if ($vip == 'VIPU' && !user_has_role('memberY')) {
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif ($vip != 'VIP' && $yellow_cards !='na') {
 		$result = get_yellow_cards_ou_color($data, $yellow_cards, $type, $prr, $arg);
 	}elseif ($vip == '' && !user_has_role('member')){
	 	$result = array('data' =>'','style' => array('color:white;background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));	
 	}else{
	 	$result = array('data' => $data,'style' => array('text-align: center;'));
 	}

	return $result;
}

function corners_ou($data, $vip, $corners, $archive = NULL, $pro = NULL, $arg = NULL){
	  global $user;
	$result = $data;
	
	if ($vip == 'VIPU' && !user_has_role('memberCC')) {
		$result = array('data' =>'','style' => array('color:white;background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif ($vip != 'VIP' && $corners !='na') {
 		$result = get_corners_ou_color($data, $corners, $archive, $pro, $arg);
 	}elseif ($vip == '' && !user_has_role('member')){
	 	$result = array('data' =>'','style' => array('color:white;background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
 	}else{
	 	$result = array('data' => $data,'style' => array('text-align: center;'));
 	}

	return $result;
	
}

function data_render_rules($data, $vip){
global $user;
	$result = $data;
	if ($vip == 'VIPU' && !user_has_role('memberCC','member1X2')) {
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif($vip == '' && !user_has_role('member')){
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}else{
	 	$result = array('data' => $data,'style' => array('text-align: center;'));
 	}

	return $result;
}

function vip_data_render_rules($data, $vip) {

global $user;
	$result = $data;
	if ($vip == 'VIPU' && !user_has_role('memberCC','member1X2')) {
		$result = array('data' =>'VIP','style' => array('color: white;background-color:#0a4805;border-right-color:#0a4805;text-align: center;'.get_3d_bgcolor(0)));
	}elseif($data == 'VIPV' && $vip == 'VIPV'){
		$result = array('data' =>'VIP','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align:center;'));
	}elseif($vip == 'VIPU' && user_has_role('memberCC','member1X2')){
		$result = array('data' =>'VIP','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align:center;'));
	}elseif($vip == '' && !user_has_role('member')) {
		$result = array('data' =>'MEM','style' => array('color: white;background-color:#0a4805;border-right-color:#0a4805;text-align: center;'.get_3d_bgcolor(1)));
	}elseif($vip == '' && user_has_role('member')) {
		$result = array('data' =>'MEM','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align:center;'));
	}

	return $result;
}


function data_render_rules_yellow_cards($data, $vip){
global $user;
	$result = $data;
	if ($vip == 'VIPU' && !user_has_role('memberY','member1X2')) {
		$result = array('data' =>'','style' => array('background-color:#0a4805;border-right-color:#0a4805;'.get_3d_bgcolor(0)));
	}elseif($vip == '' && !user_has_role('member')) {
		$result = array('data' =>'','style' => array('color: white;background-color:#0a4805;border-right-color:#0a4805;text-align: center;'.get_3d_bgcolor(0)));
	}elseif($vip == '' && user_has_role('member')) {
		$result = array('data' =>$data,'style' => array('text-align: center;'));
	}

	return $result;
}

function vip_data_render_rules_yellow_cards($data, $vip) {

global $user;
	$result = $data;
	if ($vip == 'VIPU' && !user_has_role('memberY','member1X2')) {
		$result = array('data' =>'VIP','style' => array('color: white;background-color:#0a4805;border-right-color:#0a4805;text-align: center;'.get_3d_bgcolor(0)));
	}elseif($data == 'VIPV' && $vip == 'VIPV'){
		$result = array('data' =>'VIP','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align: center;'));
  }elseif($vip == 'VIPU' && user_has_role('memberY','member1X2')){
		$result = array('data' =>'VIP','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align: center;'));
	}elseif($vip == '' && !user_has_role('member')) {
		$result = array('data' =>'MEM','style' => array('color: white;background-color:#0a4805;border-right-color:#0a4805;text-align: center;'.get_3d_bgcolor(1)));
	}elseif($vip == '' && user_has_role('member')) {
		$result = array('data' =>'MEM','style' => array('background-color:#0a4805;border-right-color:#0a4805;color: white;text-align:center;'));
	}

	return $result;
}

function get_result_color($data, $home, $away){
$data = trim($data);
	 switch ($data) {
    case '1':
        if ((int) $home > (int) $away) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    case '2':
        if ((int)$home < (int)$away) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    case '1X':
    	    if ((int)$away + 10 <= (int)$home + 10) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    case 'X2':
         if ((int)$home <= (int)$away) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
     case 'X':
         if ((int)$home+10 == (int)$away+10) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}    	   
      break;
    }
 
}

function get_bts_color($data, $home, $away){
	
	switch ($data) {
    case 'Yes':
        if ((int)$home > 0 && (int)$away > 0) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    case 'No':
        if (((int)$home + (int)$away) == 0 || (int)$home == 0  || (int)$away  == 0 ) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    }
}

function get_goals_ou_color($data, $home, $away){

	 $array_data   = explode(' ', $data);
	 $str_indes    = $array_data[0];
	 if(!empty($array_data[1]))
	 $score_result =  (float) $array_data[1] * 10;
	 
		switch ($str_indes) {
    case 'O':
        if (((int)$home + (int)$away) * 10 > $score_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}
        	elseif(((int)$home + (int)$away) * 10 == $score_result){ 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;font-size: 10px;'));	
        	}
        	else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
    case 'U':
        if (((int)$home + (int) $away) * 10 < $score_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;font-size: 10px;')); 
        	}
        	elseif(((int)$home + (int)$away) * 10 == $score_result){ 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;font-size: 10px;'));	
        	}
        	else{ 
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;font-size: 10px;'));	
        	}
        break;
     default:
        return array('data' => $data,'style' => array('color:#FF9900;font-weight: bold;font-size: 10px;'));
    }
	
}

function get_yellow_cards_ou_color($data, $yellow_cards_result, $archive = NULL, $prr = NULL, $arg = NULL){

   if(!empty($data))
	 $array_data          = explode(' ', $data);
	 $str_indes           = $array_data[0];
	 if(!empty($array_data[1]))
	 $yellow_cards        = (float) $array_data[1] * 10;
	 $yellow_cards_result = (int) $yellow_cards_result * 10;

	 if ($archive != 'archive') {
	 switch ($str_indes) {
    case 'O':
        if ((int)$yellow_cards < $yellow_cards_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif((int)$yellow_cards == $yellow_cards_result){  
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}
        break;
    case 'U':
        	if ((int)$yellow_cards > $yellow_cards_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif((int)$yellow_cards == $yellow_cards_result){ 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}
        break;
    }
	}else{
		if($prr != 'High' && $arg != 'yc_free'){
			return array('data' => '');
		}else{
		switch ($str_indes) {
    case 'O':
        if ((int)$yellow_cards < $yellow_cards_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif((int)$yellow_cards == $yellow_cards_result){  
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}
        break;
    case 'U':
        	if ((int)$yellow_cards > $yellow_cards_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif((int)$yellow_cards == $yellow_cards_result){ 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}
        break;
		}
	 }
  }
}


function get_corners_ou_color($data, $corners, $archive = NULL, $pro = NULL, $arg = NULL){
	 
	 $array_data     = explode(' ', $data);
	 $str_indes      = $array_data[0];
	 if(!empty($array_data[1]))
	 $corners_ou     = (float) $array_data[1] * 10;
	 $corners_result = (int) $corners * 10;
	 if ($archive != 'archive') {
		switch ($str_indes) {
    case 'O':
        if ((int)$corners_ou < $corners_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif ((int)$corners_ou == $corners_result) { 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}

        break;
    case 'U':
          if ((int)$corners_ou > $corners_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif ((int)$corners_ou == $corners_result) { 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}

        break;

    }
	}else{
		if($pro != 'High' && $arg != 'yc_free'){
			return array('data' => '');
		}else{
		switch ($str_indes) {
    case 'O':
        if ((int)$corners_ou < $corners_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif ((int)$corners_ou == $corners_result) { 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}

        break;
    case 'U':
          if ((int)$corners_ou > $corners_result) { 
        		return array('data' => $data,'style' => array('color:green;font-weight: bold;text-align: center;')); 
        	}elseif ((int)$corners_ou == $corners_result) { 
	        	return array('data' => $data,'style' => array('color:#D48D0B;font-weight: bold;text-align: center;'));	
        	}else{
	        	return array('data' => $data,'style' => array('color:red;font-weight: bold;text-align: center;'));	
        	}

        break;
			}
		}
	}
}

function get_flag($iso) {
$flag = '';
	if($iso){
	 
	 $flag = '<img src="sites/default/modules/custom/predictor/Flags/'.strtolower($iso).'.gif" alt="ad" width="" height="" />';
			
	}
	
	return $flag;
	
}

function get_prr_coloring($prr,$vip){
$result  = '';
if($vip == 'VIPU'){
	$result = data_render_rules($prr, $vip);
}else{
	if($prr != 'na'){	
		 if ((int) $prr >= 75) {
			  $result  =  array('data' => $prr,'style' => array('color:white ;background-color:#0a4805; font-weight: bold; font-size: 10px;' ));
		 }
	
		 elseif (intval($prr) <= -75) {
			  $result  =  array('data' => $prr,'style' => array('color:white ;background-color:#0a4805; font-weight: bold; font-size: 10px;' ));
		 }
		 
		 elseif(75 > (int) $prr && (int) $prr >= 60){
				$result  =  array('data' => $prr,'style' => array('color:white ;background-color:#117f09; font-weight: bold; font-size: 10px;' ));
		 }
		 elseif(-75 < intval($prr) && intval($prr) <= -60){
				$result  =  array('data' => $prr,'style' => array('color:white ;background-color:#117f09; font-weight: bold; font-size: 10px;' ));
		 }
	
		 elseif(60 > (int) $prr && (int) $prr >= 50){
				$result  =  array('data' => $prr,'style' => array('color:white ;background-color:#19c20d; font-weight: bold; font-size: 10px;' ));
		 }
		 elseif(-60 < (int) $prr && (int) $prr <= -50){
				$result  =  array('data' => $prr,'style' => array('color:white ;background-color:#19c20d; font-weight: bold; font-size: 10px;' ));
		 }
	
		 elseif(50 > (int) $prr){
				$result  =  array('data' => $prr,'style' => array('color:black ;font-weight: bold; font-size: 10px;' ));
		 }	 
		 elseif(-50 > (int) $prr){
				$result  =  array('data' => $prr,'style' => array('color:black ;font-weight: bold; font-size: 10px;' ));
		 }
	
	 }
}
 return $result;
}


function get_yc_prr_coloring($prr){
	
			switch ($prr) {
    case 'High':
        		return array('data' => $prr,'style' => array('color:white;background:#0D6B05;text-align: center;')); 
        break;
    case 'Medium':
        		return array('data' => $prr,'style' => array('color:white;background:#1CA80F;text-align: center;')); 
        break;
    case 'Low':
        		return array('data' => $prr,'style' => array('color:white;background:#25F213;text-align: center;')); 
        break;  
    case 'Weak':
        		return array('data' => $prr,'style' => array('color:white;background:#9E9E9E;text-align: center;')); 
        break;       
    }
}


function get_date() {
	$sql = db_query("SELECT date FROM predictor_league GROUP BY date")->fetchAll();
	
	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Date"; 
	
 foreach ($arr as $val) {
		$new_array[date('m/d/Y',$val->date)] = date('m/d/Y',$val->date);
	
 }	
	return $new_array;
}

function get_country() {
	$sql = db_query("SELECT country FROM predictor_league GROUP BY country")->fetchAll();

	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Country"; 
	
 foreach ($arr as $val) {
		$new_array[$val->country] = ucfirst(strtolower($val->country));
	
 }	
	return $new_array;
}

function get_corners_date() {
	$sql = db_query("SELECT date FROM predictor_corners GROUP BY date")->fetchAll();
	
	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Date"; 
	
 foreach ($arr as $val) {
		$new_array[date('m/d/Y',$val->date)] = date('m/d/Y',$val->date);
	
 }	
	return $new_array;
}

function get_corners_country() {
	$sql = db_query("SELECT country FROM predictor_corners GROUP BY country")->fetchAll();

	$arr          = $sql;
	$new_array    = array();
	$new_array[0] = "Select Country"; 
	
 foreach ($arr as $val) {
		$new_array[$val->country] = ucfirst(strtolower($val->country));
	
 }	
	return $new_array;
}

function get_3d_bgcolor($color) {

   if ($color == 0){
    		$color = '#0D6B05';
    }
    if ($color == 1) {
	    $color = '#1CA80F';
    }

    $bgcolor = 'background: -moz-linear-gradient('.$color.', rgb(0, 0, 0)); background:linear-gradient('.$color.', rgb(0, 0, 0))';
	
	return $bgcolor;
}

function user_has_role($roles) {
    //checks if user has role/roles
    return !!count(array_intersect(is_array($roles)? $roles : array($roles), array_values($GLOBALS['user']->roles)));
};

function get_stat_link($country, $league, $home, $away) {
	
	$img = '<img src="sites/default/modules/custom/predictor/img/3d_bar_chart.png" alt="H2H comparison" title="H2H comparison" width="16" height="16" />';
	
	$link = l($img, 'http://www.betandrelax.com/teams-comparison', array('query' => array('country' => $country,'league'=>$league,'full_matches' => 0,'ha_matches'=>0, 'home'=> $home, 'away'=> $away,'qt-stat'=>0),'html' => true,'attributes' => array('target'=>'_blank')));

	
return $link;
}


