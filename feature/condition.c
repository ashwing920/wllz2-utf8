// condition.c

#include <condition.h>

mapping conditions;
mapping query_CONDITION()
{
        mapping m=([]);
        m["conditions"] = conditions;
        return m;
}

int set_CONDITION(mapping m)
{
        if( !mapp(m) )
                return 0;
        conditions = m["conditions"];
        return 1;
}
nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;
	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {
		cnd_d = find_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) {
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));
			if( err || !cnd_d ) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				map_delete(conditions, cnd[i]);
				continue;
			}
		}
	
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( conditions[cnd[i]]<1 ) map_delete(conditions, cnd[i]);
		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;
	return update_flag;
}
// apply_condition()
nomask void apply_condition(string cnd, mixed info)
{
	if (! stringp(cnd))
	{
		log_file("condition.err", sprintf("Error to apply condition(%O) from object(%O) with info(%O)\n", cnd, previous_object(), info));
		return;
	}

	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}
nomask mixed query_condition(string cnd)
{
        if(!cnd) return conditions;
	if(!mapp(conditions) || undefinedp(conditions[cnd]) ) 
		return 0;
	return conditions[cnd];
}
nomask void clear_condition()
{
	int i;
	string *cnds;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return;
	cnds = keys(conditions);
	while(i--){
		if(CONDITION_D(cnds[i])->type() == "no_clear") continue;
		map_delete(conditions,cnds[i]);
	}
}
