<?php
function get_year_table() {
	$year = toArray(get_all_yc_year());
	$year_array = array();

foreach($year as $key => $value) {
	foreach($value as $k => $v) {
		$year_array[$key][$k] = $v;
		$year_array[$key]['yc_total']    = $value['total'];
		$year_array[$key]['yc_won']      = get_total_yc_won($value['year']);
		$year_array[$key]['yc_percent']  = round(get_total_yc_won($value['year']) / $value['total'] * 100);
		$year_array[$key]['cor_total']   = get_corr_total_by_year($value['year']);
		$year_array[$key]['cor_won']     = get_total_corners_won($value['year']);
		$year_array[$key]['cor_percent'] = ceil(get_total_corners_won($value['year']) / get_corr_total_by_year($value['year']) * 100);
		$year_array[$key]['month']       = toArray(get_yc_month($value['year']));
	}
	unset($year_array[$key]['total']);
}


foreach ($year_array as $key=>$value) {
		foreach($value['month'] as $k => $v) {
		  $year_array[$key]['month'][$k]['yc_total']    = $year_array[$key]['month'][$k]['total'];
			$year_array[$key]['month'][$k]['yc_won']      = get_total_yc_won($value['year'], $value['month'][$k]['month']);
			$year_array[$key]['month'][$k]['yc_percent']  = ceil(get_total_yc_won($value['year'], $value['month'][$k]['month']) / $year_array[$key]['month'][$k]['total'] * 100);
			$year_array[$key]['month'][$k]['cor_total']   = get_corr_total_month_year($value['year'], $value['month'][$k]['month']);
			$year_array[$key]['month'][$k]['cor_won']     = get_total_corners_won($value['year'], $value['month'][$k]['month']);
			$year_array[$key]['month'][$k]['cor_percent'] = ceil(get_total_corners_won($value['year'], $value['month'][$k]['month']) / get_corr_total_month_year($value['year'], $value['month'][$k]['month']) * 100);
			unset($year_array[$key]['month'][$k]['total']);
		}
}

$html = '<tr>';
 foreach ($year_array as $key=>$value) {
	foreach ($value as $k => $v) {

    if ($k == 'month') {
		$i = 0;
		   foreach ($value['month'] as $ks => $vl) {
		     if (0 == $i % 2) {
        $html .= '<tr class=even>';// 
    }
    else {
       $html .= '<tr class=odd>'; // odd
    }
      
				 foreach ($vl as $name => $val) {
				 
				 if (is_string($val)) {
				 	$from = generate_from_to_date($val, $value['year'], 'from');
				 	$to   = generate_from_to_date($val, $value['year'], 'to');
				 }
				   $val = is_string($val) ? '<a target=\'_blank\' href=\'http://www.betandrelax.com/predictor_archive/yc_vip?from='.$from.'&to='.$to.'\'>'.$val.'</a>' : $val;
				 
					 $html .= '<td style=width:100px class=month id=month-'.$value['year'].'>'.$val.'</td>';
					}
	    	   $html .= '</tr>';
	    	   $i++;
				}
	  }
     else{
				$html .= '<td style=width:100px class=year id=year-'.$value['year'].'>'.$v.'</td>';
			}
		}
			$html .= '</tr>';	 
	}
	return $html;
}


function get_table() {

 $output = '<table id=vip-stat style="width: 100%;text-align:center!important;">
 		<thead>
	 		<tr class=colspan-header>
	        <th></th>
	        <th colspan="3">Yellow Cards</th>
	        <th colspan="3">Corners</th>
	    </tr>
	    <tr class=header>
			    <th style="background: white;text-align:center;"></th>
	        <th style="background: white;text-align:center;">Total</th>
	        <th style="background: white;text-align:center;">WON</th>
	        <th style="background: white;text-align:center;">%</th>
	        <th style="background: white;text-align:center;">Total</th>
	        <th style="background: white;text-align:center;">WON</th>
	        <th style="background: white;text-align:center;">%</th>
	        
	    </tr>
 		</thead>
     <tr class=total>
        <td>Total</td>
        <td>'.get_total_yc().'</td>
        <td>'.get_total_yc_won().'</td>
        <td>'.ceil((get_total_yc_won()/get_total_yc()) *100) .'</td>
        <td>'.get_total_corr().'</td>
        <td>'.get_total_corners_won().'</td>
        <td>'.ceil((get_total_corners_won()/get_total_corr()) *100) .'</td>
    </tr>
		'.get_year_table().'
</table>
<div style="font-weight:bold;padding:5px;"><span style="color:rgb(203, 87, 87)";>Note*</span>: Yellow Cards picks avg. odds - 1.85 / Corners picks avg. odds - 1.55.</div>
<div style="font-weight: bold;padding-left: 5px;font-size: 17px;text-align: center;border-bottom: 1px dashed silver;border-top:1px dashed silver;">
		<span style="color:#8E0000";>This is no longer betting! This is a consistent business with yield up to 20%</span>
</div>';
	return $output;
}


function get_total_yc() {
	$sql  = db_query("SELECT COUNT(*) AS total FROM predictor_corners_archive WHERE prr_yc = 'High'")->fetchAll();
return $sql[0]->total;
}

function get_total_corr() {
	$sql  = db_query("SELECT COUNT(*) AS total FROM predictor_corners_archive WHERE prr_cor ='High'")->fetchAll();
return $sql[0]->total;
}

function get_total_over_yc($year = NULL, $month = NULL) {
	db_query("set time_zone = '+01:00'");
	$query = "SELECT COUNT(*) AS yc_over
										FROM predictor_corners_archive
										WHERE SUBSTRING(yellow_cards_ou,2)*10 < yellow_cards*10
										AND prr_yc = 'High'
										AND yellow_cards_ou LIKE 'O%'";
										
if ($year) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year "; 
}

if ($month) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%M') = '".$month."' ";
}
	$sql  = db_query($query)->fetchAll();
	$data = $sql[0]->yc_over;

return $data;
}

function get_total_yc_won($year = NULL, $month = NULL) {
	db_query("set time_zone = '+01:00'");
	$query = "SELECT COUNT(*) AS yc_under
										FROM predictor_corners_archive
										WHERE SUBSTRING(yellow_cards_ou,2)*10 > yellow_cards*10
										AND prr_yc = 'High'
										AND yellow_cards_ou LIKE 'U%'";
										
if ($year) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year "; 
}									

if ($month) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%M') = '".$month."'"; 
}
	$sql  = db_query($query)->fetchAll();
	$data = $sql[0]->yc_under + get_total_over_yc($year,$month);

return $data;
}

function get_total_over_corners($year = NULL, $month = NULL) {
	db_query("set time_zone = '+01:00'");
	$query = "SELECT COUNT(*) AS cor_over
										FROM predictor_corners_archive
										WHERE SUBSTRING(corners_ou,2)*10 < corner*10
										AND prr_cor = 'High'
										AND corners_ou LIKE 'O%'";

if ($year) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year "; 
}	

if ($month) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%M') = '".$month."' "; 
}

	$sql  = db_query($query)->fetchAll();
	$data = $sql[0]->cor_over;

return $data;
}

function get_total_corners_won($year = NULL, $month = NULL) {
	db_query("set time_zone = '+01:00'");
	$query = "SELECT COUNT(*) AS cor_under
										FROM predictor_corners_archive
										WHERE SUBSTRING(corners_ou,2)*10 > corner*10
										AND prr_cor = 'High'
										AND corners_ou LIKE 'U%'";
										
if ($year) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year "; 
}

if ($month) {
	$query .= "AND DATE_FORMAT(FROM_UNIXTIME(date), '%M') = '".$month."' "; 
}											

	$sql  = db_query($query)->fetchAll();
	$data = $sql[0]->cor_under + get_total_over_corners($year, $month);

return $data;
}

function get_all_yc_year() {
	db_query("set time_zone = '+01:00'");
	$sql  = db_query("SELECT DATE_FORMAT(FROM_UNIXTIME(date), '%Y') AS year, 
										COUNT(*) AS total 
										FROM predictor_corners_archive
										WHERE prr_yc ='High'
										GROUP BY DATE_FORMAT(FROM_UNIXTIME(date), '%Y')
										ORDER BY DATE_FORMAT(FROM_UNIXTIME(date), '%Y') DESC")->fetchAll();
 return $sql;
}

function get_corr_total_by_year($year) {
	db_query("set time_zone = '+01:00'");
	$sql  = db_query("SELECT DATE_FORMAT(FROM_UNIXTIME(date), '%Y') AS year, 
										COUNT(*) AS total 
										FROM predictor_corners_archive
										WHERE prr_cor ='High'
										AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year 
										GROUP BY DATE_FORMAT(FROM_UNIXTIME(date), '%Y')")->fetchAll();
	$data = $sql[0]->total;

return $data;
}

function get_yc_month($year) {
	db_query("set time_zone = '+01:00'");
	$sql  = db_query("SELECT DATE_FORMAT(FROM_UNIXTIME(date), '%M') AS month, 
										COUNT(*) AS total FROM predictor_corners_archive
										WHERE prr_yc ='High'
										AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year
										GROUP BY DATE_FORMAT(FROM_UNIXTIME(date), '%Y-%m')
										ORDER BY DATE_FORMAT(FROM_UNIXTIME(date), '%m') DESC")->fetchAll();

return $sql;
}

function get_corr_total_month_year($year, $month) {
	db_query("set time_zone = '+01:00'");
	$sql  = db_query("SELECT DATE_FORMAT(FROM_UNIXTIME(date), '%Y') AS year, 
										COUNT(*) AS total 
										FROM predictor_corners_archive
										WHERE prr_cor ='High'
										AND DATE_FORMAT(FROM_UNIXTIME(date), '%Y') = $year 
										AND DATE_FORMAT(FROM_UNIXTIME(date), '%M') = '".$month."'
										GROUP BY DATE_FORMAT(FROM_UNIXTIME(date), '%Y')
										ORDER BY DATE_FORMAT(FROM_UNIXTIME(date), '%m') DESC")->fetchAll();
	$data = $sql[0]->total;

return $data;
}

function toArray($obj) {
    if (is_object($obj)) $obj = (array)$obj;
    if (is_array($obj)) {
        $new = array();
        foreach ($obj as $key => $val) {
            $new[$key] = toArray($val);
        }
    } else {
        $new = $obj;
    }

    return $new;
}

function generate_from_to_date($month, $year, $type) {
	
	$month = date('m', strtotime($month));
	$from  = $month.'/01/'.$year;
	$to    = date('m/d/Y', strtotime($from."next month - 1 hour"));
	
	if ($type == 'from') {
		$result = $from;
	}
	 elseif ($type == 'to') {
		$result = $to;
	}
	
	return $result;	
}