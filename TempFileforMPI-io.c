	int dims[2],periods[2],coords[2],tile_size[2],frame_size[2];

//MPI_Init(&argc,&argv);
	//MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	dims[0]=dims[1]=sqrt(world_size);
	periods[0]=periods[1]=0;

	//dims - no of rows/cols in grid, periods - grid periodic (1/0)	
	MPI_Cart_create(MPI_COMM_WORLD,2,dims,periods,0,&comm);
	//MPI_Comm_rank(comm,&rank);

	//return the coordinates of current process grid
	MPI_Cart_coords(comm,rank,2,coords);

	//MPI_Type_contiguous(3,MPI_BYTE,&rgbtype);
	//MPI_Type_commit(&rgbtype);
	frame_size[1]=width;//width
	frame_size[0]=height;//height
	tile_size[1]=frame_size[1]/sqrt(world_size);//width
	tile_size[0]=frame_size[0]/sqrt(world_size);//height
	start_indices[0]=coords[0]*tile_size[0];start_indices[1]=coords[1]*tile_size[1];
	
	//if(rank==0)
	//printf("framesize:%d,%d, tilesize:%d,%d, start_ind:%d,%d\n",frame_size[0],frame_size[1],tile_size[0],tile_size[1],start_indices[0],start_indices[1]);
	MPI_Type_create_subarray(2,frame_size,tile_size,start_indices,MPI_ORDER_C,rgbtype,&filetype);
	MPI_Type_commit(&filetype);

	//Open file 
	buf=malloc(tile_size[0]*tile_size[1]*sizeof(double));
	memset(buf,0,tile_size[1]*tile_size[0]*sizeof(double));
	header_size=40;

	MPI_File_open(comm,filename,MPI_MODE_RDWR,MPI_INFO_NULL,&fh);
	MPI_File_set_view(fh,header_size,MPI_DOUBLE,filetype,"native",MPI_INFO_NULL);	
	{		
		MPI_File_read_all(fh,buf,tile_size[0]*tile_size[1],MPI_DOUBLE,&status);
	}




	MPI_File_close(&fh);
	MPI_Finalize();