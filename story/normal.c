
#include <ansi.h>

private mixed *story = ({
	"江湖风平浪静，波澜不惊。",
});
private void create()
{
	seteuid(getuid());
}
mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

