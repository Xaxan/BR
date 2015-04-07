<?php


function get_corners_header(){

	  $header[] = array(
    'date'        => array('data' =>'Match info', 'colspan' => 7, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000);'), 
    'class'=> array('sticky-header')),
    
    'competition' => array('data' =>'Rates', 'colspan' => 1, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'home_team'   => array('data' =>'Predictions', 'colspan' => 1, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'away_team'   => array('data' =>'Results', 'colspan' => 1, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'w1'          => array('data' =>'Status', 
    'style' => array('width: 36px!important;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'stat'          => array('data' =>'Stats', 
    'style' => array('width: 36px!important;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),	
  );


	  $header[] = array(
    'date'            => array('data' => t('Date'), 'field' => 'u.date','style' => array('width:762px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'time' => array('data' => t('Time'), 'field' => 'u.time','style' => array('width:85px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'flags'      => array('data' => t('Fl'), 'field' => 'u.flags','style' => array('width:84px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'country'      => array('data' => t('Country'), 'field' => 'u.country','style' => array('width:682px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'competition'     => array('data' => t('League Name'), 'field' => 'u.competition','style' => array('width:1009px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'home_team'       => array('data' => t('Home Team'), 'field' => 'u.home_team','style' => array('width: 1341px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'away_team'       => array('data' => t('Away Team'), 'field' => 'u.away_team','style' => array('width: 1271px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


/*
    'prr' => array('data' => t('PrR (YC)'), 'field' => 'u.time','style' => array('width: 46px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
*/

    'pro'      => array('data' => t('PrR (Cor)'), 'field' => 'u.flags','style' => array('width:1	px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

/*
    'yellow_cards_ou' => array('data' => t('YC O/U'), 'field' => 'u.yellow_cards_ou','style' => array('width:53px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
*/

    'corners_ou'      => array('data' => t('Cor O/U'), 'field' => 'u.corners_ou','style' => array('width:49px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

/*
   'yellow_cards'    => array('data' => t('YC'), 'field' => 'u.yellow_cards','style' => array('width: 49px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
*/

    'corner'          => array('data' => t('Cor'), 'field' => 'u.corner','style' => array('background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'vip'            => array('data' => t('VIP'), 'field' => 'u.vip','style' => array('background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'stat'            => array('data' => t('Comp'), 'field' => 'u.stat','style' => array('background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

  );
	
	return $header;
}

function get_corners_table_data(){
 $header = get_corners_header();

	$query = db_select('predictor_corners', 'u')
	->extend('TableSort');


// Check if there is sorting request
if(isset($_GET['sort']) && isset($_GET['order'])){
  // Sort it Ascending or Descending?
  if($_GET['sort'] == 'asc')
    $sort = 'ASC';
  else
    $sort = 'DESC';
   // Which column will be sorted
   switch($_GET['order']){
     case 'Date':
       $order = 'date';
       break;
     case 'Time':
       $order = 'time';
       break;
     case 'Country':
       $order = 'country';
       break;
     case 'League Name':
       $order = 'competition';
       break;
     case 'Home Team':
       $order = 'home_team';
       break;
     case 'Away Team':
       $order = 'away_team';
       break;
     case 'VIP':
       $order = 'vip';
       break;
     default:
       $order = 'date';
   }
 }
 else {
   // Default sort
   $sort = 'ASC';
   $order = ' date';
 }

 if (isset($_GET['date']) && isset($_GET['country'])) {

	if($_GET['date']!='0') {
		$query->condition('u.date', '%' . db_like(strtotime($_GET['date'])) . '%', 'LIKE');
	}
	
	if($_GET['country']!='0') {
			$query->condition('u.country', '%' . db_like($_GET['country']) . '%', 'LIKE');
	}

}
	else{
		variable_set('corner_date', '0');
		variable_set('corner_country', '0');
}

	$is_full = variable_get('publish_full', 0);
  
  if ($is_full != 1) {
		$result = $query->fields('u', array('date','time','iso','country','competition', 'home_team', 'away_team','prr_yc','prr_cor','yellow_cards_ou', 'corners_ou',   'yellow_cards', 'corner', 'vip'))
		->condition('prr_cor', 'High','=')
		->orderBy($order, $sort)
		->execute();
  }else{
		$result = $query->fields('u', array('date','time','iso','country','competition', 'home_team', 'away_team','prr_yc','prr_cor','yellow_cards_ou', 'corners_ou',   'yellow_cards', 'corner', 'vip'))
		->orderBy($order, $sort)
		->execute();
	}

$rows = array();
foreach ($result as $scores) {

 $rows[] = array(
    'date'            => date('m/d/Y',$scores->date),
    'time'            => array('data' => $scores->time, 'style' => array('white-space:nowrap;')),
    'flags'           => array('data' => get_flag($scores->iso), 'style' => array('white-space:nowrap;')),
    'country'         => array('data' => $scores->country, 'style' => array('white-space:nowrap;')),
    'competition'     => array('data' => $scores->competition, 'style' => array('white-space:nowrap;')),
    'home_team'       => array('data' => $scores->home_team, 'style' => array('white-space:nowrap;')),
    'away_team'       => array('data' => $scores->away_team, 'style' => array('white-space:nowrap;')),
    //'prr'             => get_yc_prr_coloring(trim($scores->prr_yc)),
    'pro'             => get_yc_prr_coloring(trim($scores->prr_cor)),
    //'yellow_cards_ou' => yellow_cards_ou_data_render_rules($scores->yellow_cards_ou, $scores->vip, $scores->yellow_cards),
    'corners_ou'      => corners_ou($scores->corners_ou, $scores->vip, $scores->corner),
    //'yellow_cards'    => data_render_rules($scores->yellow_cards, $scores->vip),
    'corner'          => data_render_rules($scores->corner, $scores->vip),
    'vip'             => vip_data_render_rules($scores->vip, $scores->vip),
    'stat'            => array('data' => get_stat_link($scores->country, $scores->competition, $scores->home_team, $scores->away_team), 'style' => array('text-align:center;')),
 );
}
 return $rows;	
}