{{#NAV_BODY}}
	{{#NAV_ITEM}}
		<li> <a href={{NAV_LINK}}> {{NAV_TITLE}} </a> </li>
	{{/NAV_ITEM}}

	{{#NAV_DROPDOWN_ITEM}}
		<li class="dropdown"> 
			<a href={{NAV_DROPDOWN_ITEM_LINK}} class="dropdown-toggle" data-toggle="dropdown"> {{NAV_DROPDOWN_ITEM_NAME}} <b class="caret"></b> </a>
			<ul class="dropdown-menu">
				{{#NAV_DROPDOWN_SUB_ITEM}}
					<li><a href={{NAV_DROPDOWN_SUB_ITEM_LINK}}> {{NAV_DROPDOWN_SUB_ITEM_NAME}} </a></li>
				{{/NAV_DROPDOWN_SUB_ITEM}}
			</ul>
		</li>
	{{/NAV_DROPDOWN_ITEM}}
{{/NAV_BODY}}