SecondCase()
{
		
	web_reg_save_param_ex(
		"ParamName=Price",
		"LB=Total Charge: $ ",
		"RB=<BR/>",
		"Ordinal=1",
		LAST);
	
	web_reg_find("Text=A First class ticket for",
         "SaveCount=FirstClassCount",
         LAST);
	
	/* Itinerary */

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("First ticket price: %d", atoi(lr_eval_string("{Price}")));
	
	lr_output_message("Amount of tickets of first class: %d",atoi(lr_eval_string("{FirstClassCount}")));
		
	return 0;
}
