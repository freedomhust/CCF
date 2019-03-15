#include<iostream>
#include<algorithm>

using namespace std;

string res_out[100];

//���ڽ�������ת�� 
void line_transfer(string &res_out){
	string::size_type pos1_ = res_out.find("_");
	string::size_type pos2_;
	while(pos1_ != string::npos){
		res_out.replace(pos1_,1,"<em>");
		pos2_ = res_out.find("_"); 
		res_out.replace(pos2_,1,"</em>");
		pos1_ = res_out.find("_");
	}
	
	string::size_type pos_text_left = res_out.find("[");
	string::size_type pos_text_right;
	string::size_type pos_link_left;
	string::size_type pos_link_right;
	string Text;
	string Link;
	string Text_Link;
	while(pos_text_left != string::npos){
		pos_text_right = res_out.find("]");
		pos_link_left = res_out.find("(");
		pos_link_right = res_out.find(")");
		Text = res_out.substr(pos_text_left+1,pos_text_right-pos_text_left-1);
		Link = res_out.substr(pos_link_left+1,pos_link_right-pos_link_left-1);
		Text_Link = "<a href=\"" + Link + "\">" + Text + "</a>";
		res_out.replace(pos_text_left,pos_link_right-pos_text_left+1,Text_Link);
		pos_text_left = res_out.find("[");
	}
}

int main(void){
	string line;
	int num;
	int is_li = 0;
	int is_p = 0;
	while(getline(cin,line)){
		//��������ڶ����� 
		if(is_p){
			//����Ѿ������� 
			if(line.size() == 0){
				is_p = 0;
			}
			//���û�н������ȡ��ǰ�� 
			else{
				res_out[num-1].erase(res_out[num-1].end()-4,res_out[num-1].end());
				res_out[num] = line + "</p>";
				line_transfer(res_out[num]);
				num++;
			}
			
		}
		//��������������б���
		else if(is_li){
			//����Ѿ������� 
			if(line.size() == 0){
				res_out[num] = "</ul>";
				num++;
				is_li = 0;
			}
			//��δ�����ͼ������н��� ���� 
			else{
				//�ҵ�֮�����һ���ո��λ�� 
				string::size_type pos_nop = line.find(" ");
				string::size_type pos_nop2 = line.find(" ",pos_nop+1);
				while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
					pos_nop = pos_nop2;
					pos_nop2 = line.find(" ",pos_nop+1);
				}
				//ɾ����ͷ���б��� 
				line = line.substr(pos_nop+1,line.size()-pos_nop-1);
				res_out[num] = "<li>" + line + "</li>";
				line_transfer(res_out[num]);
				num++;
			}
		}
		//�����һ���µĿ�ʼ 
		else{
			if(line.size() != 0){
				//�ж����Ƿ��Ǳ���
				string::size_type pos1 = line.find("# ");
				string::size_type pos2 = line.find("## ");
				string::size_type pos3 = line.find("### ");
				string::size_type pos4 = line.find("#### ");
				string::size_type pos5 = line.find("##### ");
				string::size_type pos6 = line.find("###### ");
				//�����һ������
				if(pos6 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h6>" + line + "</h6>";
					line_transfer(res_out[num]);
					num++; 
				}
				else if(pos5 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h5>" + line + "</h5>";
					line_transfer(res_out[num]);
					num++; 
				} 
				else if(pos4 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h4>" + line + "</h4>";
					line_transfer(res_out[num]);
					num++; 
				}
				else if(pos3 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h3>" + line + "</h3>";
					line_transfer(res_out[num]);
					num++; 
				}
				else if(pos2 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h2>" + line + "</h2>";
					line_transfer(res_out[num]);
					num++; 
				}
				else if(pos1 != string::npos){
					//�ҵ�֮�����һ���ո��λ�� 
					string::size_type pos_nop = line.find(" ");
					string::size_type pos_nop2 = line.find(" ",pos_nop+1);
					while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
						pos_nop = pos_nop2;
						pos_nop2 = line.find(" ",pos_nop+1);
					}
					//ɾ����ͷ�ı����� 
					line = line.substr(pos_nop+1,line.size()-pos_nop-1);
					res_out[num] = "<h1>" + line + "</h1>";
					line_transfer(res_out[num]);
					num++; 
				}
				
				//���Ǳ���
				else{
					//�ж��ǲ����б�
					string::size_type pos_star = line.find("* ");
					//������б� 
					if(pos_star != string::npos){
						//�ҵ�֮�����һ���ո��λ�� 
						string::size_type pos_nop = line.find(" ");
						string::size_type pos_nop2 = line.find(" ",pos_nop+1);
						while(pos_nop2 != string::npos && pos_nop2 == pos_nop+1){
							pos_nop = pos_nop2;
							pos_nop2 = line.find(" ",pos_nop+1);
						}
						//ɾ����ͷ���б��� 
						line = line.substr(pos_nop+1,line.size()-pos_nop-1);
						is_li = 1;
						res_out[num] = "<ul>";
						num++;
						res_out[num] = "<li>" + line + "</li>"; 
						line_transfer(res_out[num]);
						num++;
					} 
					//����Ƕ��� 
					else{
						is_p = 1;
						res_out[num] = "<p>" + line + "</p>";
						line_transfer(res_out[num]);
						num++;
					} 
				}
			} 
		} 
	}
	if(is_li){
		res_out[num] = "</ul>";
		num++;
	} 
	for(int i = 0; i < num; i++){
		cout << res_out[i] << endl;
	}
}
