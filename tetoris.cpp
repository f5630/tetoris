

//テトリス生成
void Tetris::newblock(){
	bode[19][6] = mino;
	posy = 19;
	posx = 6;
}


//左に移動
void Tetris::move_left(){
	if(posx - 1 >= 0){
		bode[posy][posx] = nothing;
		posx--;
	}
	bode[posy][posx] = mino;
}

//右に移動
void Tetris::move_right(){
	if(posx + 1 < 12){
		bode[posy][posx] = nothing;
		posx++;
	}
	bode[posy][posx] = mino;
}

//下に移動
void Tetris::move_bottom(){
	int y;
	for(y = 19; y < 0;y--){
		if(bode[y][posx] != nothing){
			break;
		}
	}

	bode[posy][posx] = nothing;
	bode[y][posx] = mino;

	posx = 0;
	posy = 0;
}

//消去判定
void check(){
	int count = 0;

	for(int y = 0;y < 20;y++){
		for(int x=0;x < 12;x++){
			if(bode[y][x] == mino){
				count++;
			}
		}

		if(count == 12){
			for(int x=0;x < 12;x++){
				bode[y][x] = nothing;
			}
		}
		count = 0;
	}
}