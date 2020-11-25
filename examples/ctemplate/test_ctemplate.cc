#include <ctemplate/template.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string>

//导航栏与页面的模板是分开的，先实例化导航栏模板并填充内容，得到导航栏的内容，再将与填充到页面的导航栏部分

int main() {
    //创建页面模板
    ctemplate::TemplateDictionary dict_page("page");
    dict_page.SetValue("TITLE", "page-sample");

    //创建导航栏模板
    ctemplate::TemplateDictionary dict_navbar("navbar");
    ctemplate::TemplateDictionary *nav_body;
    ctemplate::TemplateDictionary *nav_item;

    //在导航栏上添加一个导航项
    nav_body = dict_navbar.AddSectionDictionary("NAV_BODY");

    //添加一个导航项到导航栏
    nav_item = nav_body->AddSectionDictionary("NAV_ITEM");
    nav_item->SetValue("NAV_LINK", "\"#\"");
    nav_item->SetValue("NAV_TITLE", "第一个导航项");

    //添加第二个导航项到导航栏
    nav_item = nav_body->AddSectionDictionary("NAV_ITEM");
    nav_item->SetValue("NAV_LINK", "\"#\"");
    nav_item->SetValue("NAV_TITLE", "第二个导航项");

    //添加一个带下拉的导航项
    nav_item = nav_body->AddSectionDictionary("NAV_DROPDOWN_ITEM");
    nav_item->SetValue("NAV_DROPDOWN_ITEM_LINK", "\"#\"");
    nav_item->SetValue("NAV_DROPDOWN_ITEM_NAME", "下拉列表");

    //为下拉导航茂增加一个下拉菜单
    ctemplate::TemplateDictionary *nav_dropdown_item;
    nav_dropdown_item = nav_item->AddSectionDictionary("NAV_DROPDOWN_SUB_ITEM");
    nav_dropdown_item->SetValue("NAV_DROPDOWN_SUB_ITEM_LINK", "\"#\"");
    nav_dropdown_item->SetValue("NAV_DROPDOWN_SUB_ITEM_NAME", "下拉项2");

    //实例化导航栏模板，得到导航栏的内容
    std::string navbar_output;
    ctemplate::Template *tpl_navbar;
    tpl_navbar = ctemplate::Template::GetTemplate("./navbar.tpl",
                                                  ctemplate::DO_NOT_STRIP);
    tpl_navbar->Expand(&navbar_output, &dict_navbar);

    //将导航栏的内容填充到页面模板
    dict_page.SetValue("NAVBAR", navbar_output);

    //实例化页面模板，输出页面内容
    std::string page_output;
    ctemplate::Template *tpl_page;
    tpl_page =
        ctemplate::Template::GetTemplate("./page.tpl", ctemplate::DO_NOT_STRIP);
    tpl_page->Expand(&page_output, &dict_page);
    printf("%s\n", page_output.c_str());

    return 0;

    // for (int i=0; i<2; ++i)
    // {
    // ctemplate::TemplateDictionary* table1_dict;
    // table1_dict = dict.AddSectionDictionary("TABLE1");
    // table1_dict->SetValue("field1", "1");
    // table1_dict->SetValue("field2", "2");

    //这里有点类似于printf
    // table1_dict->SetFormattedValue("field3", "%d", i);
    // }

    // std::string output;
    // ctemplate::Template* tpl;
    // tpl = ctemplate::Template::GetTemplate("page.html",
    // ctemplate::DO_NOT_STRIP); tpl->Expand(&output, &dict); printf("%s\n",
    // output.c_str());

    return 0;
}