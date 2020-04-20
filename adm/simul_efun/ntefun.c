#define SUCCESS         0
#define FAIL            1

int mapping_eqv(mapping m1, mapping m2);


int array_eqv(mixed arr1, mixed arr2)
{
        int s_arr = sizeof(arr1);
        if( s_arr != sizeof(arr2) ) return 0;
        if( s_arr < 1 ) return 1;
        for( int i=0; i<sizeof(arr1); i++ ) {
                if( arrayp(arr1[i]) && arrayp(arr2[i]) ) {
                        if( !array_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( mapp(arr1[i]) && mapp(arr2[i]) ) {
                        if( !mapping_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( arr1[i] != arr2[i] ) return 0;
        }
        return 1;
}

int mapping_eqv(mapping map1, mapping map2)
{
        int m_arr = sizeof(map1);
        mixed m_keys1, m_keys2;

        if( m_arr != sizeof(map2) ) return 0;
        if( m_arr < 1 ) return 1;
        m_keys1 = keys(map1);
        m_keys2 = keys(map2);

        for( int i=0; i<sizeof(m_keys1); i++ ) {
                if( mapp(m_keys1[i]) && mapp(m_keys2[i]) ) {
                        if( !mapping_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( arrayp(m_keys1[i]) && arrayp(m_keys2[i]) ) {
                        if( !array_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( m_keys1[i] != m_keys2[i] ) {
                        return 0;
                }

                // Value check
                if( mapp(map1[m_keys1[i]]) && mapp(map2[m_keys2[i]]) ) {
                        if( !mapping_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( arrayp(map1[m_keys1[i]]) && arrayp(map2[m_keys1[i]]) ) {
                        if( !array_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( map1[m_keys1[i]] != map2[m_keys2[i]] ) return 0;
        }
        return 1;
}
string base_dir(object obj)
{
        string filename;
        int at;

        filename = base_name(obj);
        at = strsrch(filename,"/",-1);
        filename = filename[0..at];
        return filename;
}