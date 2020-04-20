
void cat(string file)
{
	seteuid(geteuid(this_player()));
	write(read_file(file));
}
void log_file(string file, string text)
{
	write_file(LOG_DIR + file, text);
}
void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");

	if (file[strlen(file) -1] != '/')
		// the file is refer to a file, not directory
		dir = dir[0..sizeof(dir)-2];

	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}

	dir = 0;
}
string base_name(object ob)
{
	string file;
	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}
int file_lines(string file)
{
#ifdef DOING_IMPROVED
        return efun::file_lines(file);
#else
        int i;
        int jmp;

        i = 65536;
        jmp = i / 2;

        while (jmp)
        {
                if (read_file(file, i, 1)) i += jmp; else
                                           i -= jmp;
                jmp /= 2;
        }

        return i - 1;
#endif
}
int is_c_file(string arg)
{
        int l;

        l = strlen(arg);
        if( arg[l - 1] == 'c' && arg[l - 2] == '.' )
                return 1;

        return 0;
}
