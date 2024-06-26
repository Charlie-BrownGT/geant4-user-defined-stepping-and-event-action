#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4GenericMessenger.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();
	
	G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
	
	virtual G4VPhysicalVolume *Construct();
	
private:
	G4Box *solidWorld, *solidRadiator, *solidDetector;
	G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector;
	G4VPhysicalVolume *physWorld, *physRadiator, *physDetector;
	G4GenericMessenger *fMessenger;
	
	G4Material *SiO2, *H2O, *Aerogel, *worldMat;
	G4Element *C;
	
	virtual void ConstructSDandField();
	void DefineMaterials();
	
	G4LogicalVolume *fScoringVolume;
	
	G4int nCols, nRows;
	G4double xWorld, yWorld, zWorld;
};
#endif
