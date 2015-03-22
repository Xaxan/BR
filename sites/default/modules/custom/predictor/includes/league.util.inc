<?php


function get_header(){

	  $header[] = array(
    'date'        => array('data' =>'Match info', 'colspan' => 7, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000);'), 
    'class'=> array('sticky-header')),
    
    'competition' => array('data' =>'Odds & Rates', 'colspan' => 5, 
    'style' => array('color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'home_team'   => array('data' =>'Predictions', 'colspan' => 3, 
    'style' => array('white-space: nowrap;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'away_team'   => array('data' =>'Results', 'colspan' => 2, 
    'style' => array('white-space: nowrap;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),
    
    'w1'          => array('data' =>'Status', 
    'style' => array('width: 36px!important;color:white;white-space:nowrap;text-align: center;background:#0A3F63; background-image: -webkit-linear-gradient(top, #0A3F63, #000000); background-image: -moz-linear-gradient(top, #0A3F63, #000000); background-image: -ms-linear-gradient(top, ##0A3F63, #000000); background-image: -o-linear-gradient(top, ##0A3F63, #000000); background-image: linear-gradient(to bottom, #0A3F63, #000000); '), 
    'class'=> array('sticky-header')),	
  );


	  $header[] = array(
    'date'            => array('data' => t('Date'), 'field' => 'u.date','style' => array('width:73px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'time' => array('data' => t('Time'), 'field' => 'u.time','style' => array('width:32px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'flags'      => array('data' => t('Fl'), 'field' => 'u.flags','style' => array('width:16px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'country'      => array('data' => t('Country'), 'field' => 'u.country','style' => array('width:77px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),


    'competition'     => array('data' => t('League Name'), 'field' => 'u.competition','style' => array('width:122px!important;white-space: nowrap;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'home_team'       => array('data' => t('Home Team'), 'field' => 'u.home_team','style' => array('width: 97px!important;white-space: nowrap;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'away_team'       => array('data' => t('Away Team'), 'field' => 'u.away_team','style' => array('width: 105px!important;white-space: nowrap;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
 'w1' => array('data' => t('W1'), 'field' => 'u.w1','style' => array('width:35px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
  'draw' => array('data' => t('Draw'), 'field' => 'u.draw','style' => array('width:20px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
    'w2' => array('data' => t('W2'),'title' => t('W22'), 'field' => 'u.w2','style' => array('width:32px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'prr' => array('data' => t('PrR'), 'field' => 'u.time','style' => array('width:34px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

    'pro' => array('data' => t('PrO'), 'field' => 'u.flags','style' => array('width: 25px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
   'result' => array('data' => t('Result'), 'field' => 'u.result','style' => array('width:35px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
  'bts' => array('data' => t('BTS'), 'field' => 'u.bts','style' => array('width: 19px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
  'goals_ou' => array('data' => t('O/U'), 'title' => t('Goals Out/Under'), 'field' => 'u.goals_ou','style' => array('width: 31px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
	'home_team_score' => array('data' => t('HTG'),'title' => t('Home Team Goals'), 'field' => 'u.home_team_score','style' => array('width: 12px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
	'away_team_score' => array('data' => t('ATG'),'title' => t('Away Team Goals'), 'field' => 'u.away_team_score','style' => array('width: 12px!important;background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),
	'vip' => array('data' => t('VIP'), 'field' => 'u.vip','style' => array('background-image: -webkit-linear-gradient(top, #0A3F63, #000000);
background-image: -moz-linear-gradient(top, #0A3F63, #000000);
background-image: -ms-linear-gradient(top, ##0A3F63, #000000);
background-image: -o-linear-gradient(top, ##0A3F63, #000000);
background-image: linear-gradient(to bottom, #FFFFFF, #DDD);')),

  );
	
	return $header;
}

function get_table_data(){
 $header = get_header();

	$query = db_select('predictor_league', 'u')
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
     case 'W1':
       $order = 'w1';
       break;
     case 'Draw':
       $order = 'draw';
       break;
     case 'W2':
       $order = 'w2';
       break;
     case 'PrR':
       $order = 'prr';
       break;
     case 'PrO':
       $order = 'pro';
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
		variable_set('league_date', '0');
		variable_set('league_country', '0');
}


	$result = $query->fields('u', array('date','time','iso','country','competition', 'home_team', 'away_team', 'w1', 'draw', 'w2','prr','pro', 'result', 'bts', 'goals_ou',/*  'yellow_cards_ou', 'corners_ou', */ 'home_team_score', 'away_team_score', /*  'yellow_cards', 'corner', */ 'vip'))
	->orderBy($order, $sort)
	->execute();

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
    'w1'              => number_format((float)$scores->w1, 2, '.', ''),
    'draw'            => number_format((float)$scores->draw, 2, '.', ''),
    'w2'              => number_format((float)$scores->w2, 2, '.', ''),
    'prr'             => get_prr_coloring($scores->prr, $scores->vip),
    'pro'             => data_render_rules($scores->pro, $scores->vip),
    'result'          => result_data_render_rules($scores->result, $scores->vip, $scores->home_team_score, $scores->away_team_score),
    'bts'             => bts_data_render_rules($scores->bts, $scores->vip, $scores->home_team_score, $scores->away_team_score),
    'goals_ou'        => goals_ou_data_render_rules($scores->goals_ou, $scores->vip, $scores->home_team_score, $scores->away_team_score),
    'home_team_score' => data_render_rules($scores->home_team_score, $scores->vip),
    'away_team_score' => data_render_rules($scores->away_team_score, $scores->vip),
    'vip'             => vip_data_render_rules($scores->vip, $scores->vip),
 );
}
 return $rows;	
}