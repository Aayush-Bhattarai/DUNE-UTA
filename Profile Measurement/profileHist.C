//This program reads data from the txt file and generates histogram

void profileHist()
{
	//Creating Histogram
	TH1D* hist = new TH1D("hist", "; Length [cm]; # of Entries", 20, 220, 222); //Bin number = (222-220)/0.1 = 20 
	
	Double_t data; //Profile length 
	ifstream fInput;

	//Working with Data Input
	fInput.open("profiles-data.txt"); 

	if(fInput.fail()) {
		std::cout << "The file did not opened!" << std::endl;
		exit(1);
	}

	while (fInput >> data) {
		hist->Fill(data);

	}

	//Drawing Histogram
	TCanvas* c1 = new TCanvas();
	gStyle->SetOptStat(11111111); //more stats
	hist->Draw();
	hist->Fit("gaus");
	hist->SetFillStyle(3002);
	hist->SetFillColor(kBlue);


}

