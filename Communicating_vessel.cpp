typedef vector<float> vec_type;

// this function gets heights of vessels that are connected and a pool of water that will fill them up, and returns the hights of the vessels and pool after filling.
//for the simplicity lets assume that are heights are ordered from short to tall
void findHight(float &Pool,vec_type &hights){
	if (Pool < 0)
		return;
	if ((*min_element(hights.begin(),hights.begin()+hights.size())) < 0 )
		return;
	float hightsSum=accumulate(hights.begin(),hights.begin()+hights.size(),0);
	if (hightsSum <= Pool){
		Pool-=hightsSum;
		return;
	}
	float avarage ;
	for (vec_type::iterator itr=hights.begin();itr != hights.end();itr++){
		avarage = Pool / float(hights.size()-(itr-hights.begin()));
		if  (*itr-avarage < 0){
			Pool-=*itr-avarage;
		}else{
			*itr=avarage;
		}
		Pool-=avarage;
	}
}