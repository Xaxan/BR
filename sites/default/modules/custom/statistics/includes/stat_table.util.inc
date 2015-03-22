<?php

function get_stat_header($home, $away, $home_img, $away_img) {

	  $header = array(
    'home'        => array('data' => strtoupper($home).''.$home_img, 
    'style' => array('font-size: 16px;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000);'), 
    'class'=> array('sticky-header')),
    
    'stat' => array('data' =>'VS',
    'style' => array('font-size: 16px;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'away'   => array('data' => strtoupper($away).''.$away_img,
    'style' => array('font-size: 16px;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
  );
	
	return $header;
}

function get_stat_table_data($form, $form_state){
	
	
	$country   =  $_GET['country'];
	$league    =  $_GET['league'];
	$stat_type =  $_GET['full_matches'];
	$home 	   =  $_GET['home'];
	$away      =  $_GET['away'];
	
	 $path = drupal_get_path('module', 'statistics') . '/img/all/'.$away.'.png';
   $away_img  = '<div id="home_image"><img src="'.$path.'"/></div>';
   
   $path = drupal_get_path('module', 'statistics') . '/img/all/'.$home.'.png';
   $home_img  = '<div id="home_image"><img src="'.$path.'"/></div>';
	
  $header    = get_stat_header($home, $away, $home_img, $away_img);
  
   if ($stat_type != 0) {
	 $stat_type = 'LIMIT '.$stat_type;
 }
  else{
	 $stat_type = '';
 }

	$home_array = get_full_stat($home, $stat_type);
	$away_array = get_full_stat($away, $stat_type);
	$result     = build_array($home_array, $away_array);
	$rows = array();

foreach ($result as $key => $stat) {

	$home_data = substr($result[$key], 0, strpos($result[$key], '_'));
	$away_data = str_replace('_','',substr($result[$key], strpos($result[$key], '_')));

	$sum = ($home_data + $away_data);
if ($sum != 0 ) {
  $pixels_home = $home_data / ($home_data + $away_data) * 100;
  $pixels_away = $away_data / ($home_data + $away_data) * 100;
}else{
	$pixels_home = 0;	
	$pixels_away = 0;	
}

 $rows[] = array(
    'home' => array('data' => '<div style="float: left;">'.$home_data.'</div>
    									<div style="float: right; width: 82%; margin-top: 4px; border: solid 1px #848484; border-right: none; height: 9px;">
    									<div id="'.get_left_class_color($home_data, $away_data).'" style="height:9px;float:right;width:'.$pixels_home.'%;"></div>
    									</div>', 
    								'style' => array('white-space:nowrap;width: 45%;font-size: 11px;font-weight: bold;color:black;')),
    'stat' => array('data' => strtoupper(CONSTANT($key)), 
    								'style' => array('white-space:nowrap;width: 10%;font-size: 11px;font-weight: bold;color:black;')),
    'away' => array('data' => '
    								<div style="float: left; width: 82%; margin-top: 4px; border: solid 1px #848484; border-left: none; height: 9px;">
    								<div id="'.get_right_class_color($home_data, $away_data).'" style="height:9px;width:'.$pixels_away.'%;"></div></div>
    								<div style="float: right;">'.$away_data.'</div>', 
    								'style' => array('white-space:nowrap;width: 45%;font-size: 11px;font-weight: bold;color:black;')),
    );
}
 return $rows;	
}

function get_hastat_table_data($form, $form_state){
	
	
	$country   =  $_GET['country'];
	$league    =  $_GET['league'];
	$ha_matches =  $_GET['ha_matches'];
	$home 	   =  $_GET['home'];
	$away      =  $_GET['away'];

	
	 $path = drupal_get_path('module', 'statistics') . '/img/all/'.$away.'.png';
   $away_img  = '<div id="home_image"><img src="'.$path.'"/></div>';
   
   $path = drupal_get_path('module', 'statistics') . '/img/all/'.$home.'.png';
   $home_img  = '<div id="home_image"><img src="'.$path.'"/></div>';
	
   $header    = get_stat_header($home, $away, $home_img, $away_img);

 if ($ha_matches != 0) {
	 $ha_matches = 'LIMIT '.$ha_matches;
 }
  else{
	 $ha_matches = '';
 }

	$home_array = get_home_stat($home, $ha_matches);
	$away_array = get_away_stat($away, $ha_matches);
  $result     = build_array($home_array, $away_array);
	$rows = array();

foreach ($result as $key => $stat) {

	$home_data = substr($result[$key], 0, strpos($result[$key], '_'));
	$away_data = str_replace('_','',substr($result[$key], strpos($result[$key], '_')));
	
	$sum = ($home_data + $away_data);
if ($sum != 0 ) {
 $pixels_home = $home_data / ($home_data + $away_data) * 100;
 $pixels_away = $away_data / ($home_data + $away_data) * 100;
}else{
	$pixels_home = 0;	
	$pixels_away = 0;	
}



 $rows[] = array(
    'home' => array('data' => '<div style="float: left;">'.$home_data.'</div>
    									<div style="float: right; width: 82%; margin-top: 4px; border: solid 1px #848484; border-right: none; height: 9px;">
    									<div id="'.get_left_class_color($home_data, $away_data).'" style="height:9px;float:right;width:'.$pixels_home.'%;"></div>
    									</div>', 
    								'style' => array('white-space:nowrap;width: 45%;font-size: 11px;font-weight: bold;color:black;')),
    'stat' => array('data' => strtoupper(CONSTANT($key)), 
    								'style' => array('white-space:nowrap;width: 10%;font-size: 11px;font-weight: bold;color:black;')),
    'away' => array('data' => '
    								<div style="float: left; width: 82%; margin-top: 4px; border: solid 1px #848484; border-left: none; height: 9px;">
    								<div id="'.get_right_class_color($home_data, $away_data).'" style="height:9px;width:'.$pixels_away.'%;"></div></div>
    								<div style="float: right;">'.$away_data.'</div>', 
    								'style' => array('white-space:nowrap;width: 45%;font-size: 11px;font-weight: bold;color:black;')),
    );
}

 return $rows;	
}