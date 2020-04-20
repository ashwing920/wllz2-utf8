// chinese.c


inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg || arg == "" ) {
		CHINESE_D->dump_translate();
		return 1;
	}

	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		if(chinz == "") {
			CHINESE_D->remove_translate( key );
			write( key + "已被删除。\n" );
		}
		else {
			CHINESE_D->add_translate(key, chinz);
			write( key + " == " + chinz + "\n已经加入字典。\n");
		}
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
指令格式：chinese 			列示英中解释字典的内容
          chinese <英文>		删除英中解释字典的项目
          chinese <英文>==<中文>	向英中解释字典增添项目

维护英中解释字典。

HELP
	);

	return 1 ;
}
