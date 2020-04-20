// transd.c
// 骑马传送的主系统

//#pragma optimize
//#pragma save_binary

private void create() { seteuid(getuid()); }

string trans_to(string site)
{
	string path;

	switch(site) {
		case "ty": path="/d/center/guangchang";	break;
		case "yz": path="/d/city/guangchang";	break;
		case "xj": path="/d/xingxiu/shanjiao";	break;
		case "bj": path="/d/city2/tian_anm";   	break;
		case "qz": path="/d/quanzhou/zhongxin";	break;
		case "fs": path="/d/foshan/westgate";	break;
		case "cd": path="/d/city3/guangchang";	break;
		case "dl": path="/d/dali/center";	break;
		case "ca": path="/d/city4/center";	break;
		case "km": path="/d/kunming/jinrilou";	break;
		case "hyc":path="/d/henshan/hengyang";	break;
		case "lz": path="/d/lingzhou/center";	break;
		case "hz": path="/d/hangzhou/qiantang";	break;
		case "sz": path="/d/suzhou/canlangting";break;
		case "xy": path="/d/xiangyang/guangchang";break;
		case "kl": path="/d/mingjiao/shanjiao";break;
		default:
			path="none";
		break;
	}
	return path;
}