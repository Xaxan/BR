<?php

function get_archive_header($arg) {
if($arg == 'league_vip' || $arg == 'league_free'){
	  
	  $header = array(
    'date'            => array('data' => t('Date'), 'field' => 'u.date'),
    'time'            => array('data' => t('Time'), 'field' => 'u.time'),
    'flags'           => array('data' => t('Flags'), 'field' => 'u.flags'),
    'country'         => array('data' => t('Country'), 'field' => 'u.country'),
    'competition'     => array('data' => t('Competition'), 'field' => 'u.competition'),
    'home_team'       => array('data' => t('Home Team'), 'field' => 'u.home_team'),
    'away_team'       => array('data' => t('Away Team'), 'field' => 'u.away_team'),
    'w1'              => array('data' => t('W1'), 'field' => 'u.w1'),
    'draw'            => array('data' => t('Draw'), 'field' => 'u.draw'),
    'w2'              => array('data' => t('W2'), 'field' => 'u.w'),
    'prr'             => array('data' => t('PrR'), 'field' => 'u.prr'),
    'pro'             => array('data' => t('PrO'), 'field' => 'u.pro'),
    'result'          => array('data' => t('Result'), 'field' => 'u.result'),
    'bts'             => array('data' => t('BTS'), 'field' => 'u.bts'),
    'goals_ou'        => array('data' => t('O/U'), 'field' => 'u.goals_ou'),
    'home_team_score' => array('data' => t('HTG'), 'field' => 'u.home_team_score'),
    'away_team_score' => array('data' => t('ATG'), 'field' => 'u.away_team_score'),
    'vip'             => array('data' => t('VIP'), 'field' => 'u.vip'),
  );
 }
  else{
	 
	 $header = array(
    'date'            => array('data' => t('Date'), 'field' => 'u.date'),
    'time'            => array('data' => t('Time'), 'field' => 'u.time'),
    'flags'           => array('data' => t('Flags'), 'field' => 'u.flags'),
    'country'         => array('data' => t('Country'), 'field' => 'u.country'),
    'competition'     => array('data' => t('Competition'), 'field' => 'u.competition'),
    'home_team'       => array('data' => t('Home Team'), 'field' => 'u.home_team'),
    'away_team'       => array('data' => t('Away Team'), 'field' => 'u.away_team'),
    'prr'             => array('data' => t('PrR'), 'field' => 'u.prr'),
    'pro'             => array('data' => t('PrO'), 'field' => 'u.pro'),
    'yellow_cards_ou' => array('data' => t('Yellow Cards OU'), 'field' => 'u.yellow_cards_ou'),
    'corners_ou'      => array('data' => t('Corners OU'), 'field' => 'u.corners_ou'),
    'yellow_cards'    => array('data' => t('Yellow Cards (Total)'), 'field' => 'u.yellow_cards'),
    'corner'          => array('data' => t('Corners (Total)'), 'field' => 'u.corner'),
    'vip'             => array('data' => t('VIP'), 'field' => 'u.vip'),
  );
 }
	return $header;
}

function get_table_datas($from, $to, $arg) {
 $header = get_archive_header($arg);

switch ($arg){
	case 'league_vip':
		$query = db_select('predictor_league_archive', 'u')
			->condition('vip', 'VIPV','=')
			->condition('date', strtotime($from),'>=')
			->condition('date', strtotime($to),'<=')
			->extend('TableSort');
	break;
	case 'league_free':
		$query = db_select('predictor_league_archive', 'u')
			->condition('vip', 'VIPV','!=')
			->condition('date', strtotime($from),'>=')
			->condition('date', strtotime($to),'<=')
			->extend('TableSort');
  break;
 	case 'yc_vip':
 						db_query("set time_zone = '+01:00'");
		$query = db_select('predictor_corners_archive', 'u')
			->condition('vip', 'VIPV','=')
			->condition('date', strtotime($from), '>=')
			->condition('date', strtotime($to), '<=')
			->extend('TableSort');
	break;
	case 'yc_free':
		$query = db_select('predictor_corners_archive', 'u')
			->condition('vip', 'VIPV','!=')
			->condition('date', strtotime($from), '>=')
			->condition('date', strtotime($to), '<=')
			->extend('TableSort');
  break;
 
}
if ($arg == 'league_vip' || $arg == 'league_free' ) {
		$result = $query->fields('u', array('date','time','iso','country','competition', 'home_team', 'away_team', 'w1', 'draw', 'w2','prr','pro', 'result', 'bts', 'goals_ou','home_team_score', 'away_team_score','vip'))
	->orderByHeader($header)
	->execute();
 }
  else{

	$result = $query->fields('u', array('date','time','iso','country','competition', 'home_team', 'away_team','prr_yc','prr_cor','yellow_cards_ou', 'corners_ou', 'yellow_cards', 'corner', 'vip'))
	->orderByHeader($header)
	->execute();	
}	
	
 $rows = get_rows($result, $arg);

 return $rows;	
}

function get_rows($result, $arg) {
	$rows = array();	
	
foreach ($result as $scores) {
 if ($arg == 'league_vip' || $arg == 'league_free' ) {
	$rows[] = array(
		 	'date'            => date('m/d/Y', $scores->date),
		 	'time'            => array('data' => $scores->time, 'style' => array('white-space:nowrap;')),
		 	'flags'           => array('data' => get_flagfor_archive($scores->iso), 'style' => array('white-space:nowrap;')),
		 	'country'         => array('data' => $scores->country, 'style' => array('white-space:nowrap;')),
		 	'competition'     => array('data' => $scores->competition, 'style' => array('white-space:nowrap;')),
		 	'home_team'       => array('data' => $scores->home_team, 'style' => array('white-space:nowrap;')),
		 	'away_team'       => array('data' => $scores->away_team, 'style' => array('white-space:nowrap;')),
		 	'w1'              => number_format((float)$scores->w1, 2, '.', ''),
		 	'draw'            => number_format((float)$scores->draw, 2, '.', ''),
		 	'w2'              => number_format((float)$scores->w2, 2, '.', ''),
		 	'prr'             => get_prr_coloring($scores->prr, $scores->vip),
		 	'pro'             => $scores->pro,
		 	'result'          => result_data_render_rules($scores->result, $scores->vip, $scores->home_team_score, $scores->away_team_score),
		 	'bts'             => bts_data_render_rules($scores->bts, $scores->vip, $scores->home_team_score, $scores->away_team_score),
	 	  'goals_ou'        => goals_ou_data_render_rules($scores->goals_ou, $scores->vip, $scores->home_team_score, $scores->away_team_score),
      'home_team_score' => data_render_rules($scores->home_team_score, $scores->vip),
      'away_team_score' => data_render_rules($scores->away_team_score, $scores->vip),
      'vip'             => vip_data_render_rules($scores->vip, $scores->vip),
		 );
}else{
	 $rows[] = array(
    'date'            => date('m/d/Y',$scores->date),
    'time'            => array('data' => $scores->time, 'style' => array('white-space:nowrap;')),
    'flags'           => array('data' => get_flagfor_archive($scores->iso), 'style' => array('white-space:nowrap;')),
    'country'         => array('data' => $scores->country, 'style' => array('white-space:nowrap;')),
    'competition'     => array('data' => $scores->competition, 'style' => array('white-space:nowrap;')),
    'home_team'       => array('data' => $scores->home_team, 'style' => array('white-space:nowrap;')),
    'away_team'       => array('data' => $scores->away_team, 'style' => array('white-space:nowrap;')),
    'prr'             => get_yc_prr_coloring($scores->prr_yc),
    'pro'             => get_yc_prr_coloring($scores->prr_cor),
    'yellow_cards_ou' => yellow_cards_ou_data_render_rules($scores->yellow_cards_ou, $scores->vip, $scores->yellow_cards, 'archive', $scores->prr_yc, $arg),
    'corners_ou'      => corners_ou($scores->corners_ou, $scores->vip, $scores->corner, 'archive', $scores->prr_cor, $arg),
    'yellow_cards'    => data_render_rules($scores->yellow_cards, $scores->vip),
    'corner'          => data_render_rules($scores->corner, $scores->vip),
    'vip'             => vip_data_render_rules($scores->vip, $scores->vip),
 );
}

}


	return $rows;	
}

function new_line($str){
 $result = str_replace("\n", "<br/>", $str);
	return $result;
}

function positive($val) {
	$val= (float)$val;
	
	if($val < 0 ){
		$result =  array('data' => number_format($val, 2),'style' => array('color:red;font-weight: bold;font-size: 11px;'));	
		
	}else{
		$result =  array('data' => number_format($val, 2));
	}
	return $result;
	
}

function get_flagfor_archive($iso) {
$flag = '';
	if ($iso) {
	 
	 $flag = '<img src="http://www.betandrelax.com/sites/default/modules/custom/predictor_archive/Flags/'.strtolower($iso).'.gif" alt="ad" width="" height="" />';
			
	}
	return $flag;
}