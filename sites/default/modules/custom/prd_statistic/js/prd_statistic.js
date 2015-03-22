(function($){

$(document).ready(function() {

	$('td.year').each(function () {
	    var ar = this.id;
	    $("td.year").parent().addClass('expandable');
	});
	
	   $("td.year").parent().addClass('expandable');
	   $("td.month").parent("tr").css("display", "none");
	   $("td.month").parent("tr").addClass('month');
	
		  $(".expandable").click(function() {
		    $(this).nextUntil('.expandable').toggle("slow");
				});
	  });
		
})(jQuery);