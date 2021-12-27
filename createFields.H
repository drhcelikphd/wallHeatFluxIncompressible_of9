//    Info << "Reading field p\n" << endl;
//    volScalarField p
//    (
//        IOobject
//        (
//            "p",
//            runTime.timeName(),
//            mesh,
//            IOobject::READ_IF_PRESENT,
//            IOobject::AUTO_WRITE
//        ),
//        mesh
//    );

    Info<< "Reading field T\n" << endl;
    volScalarField T
    (
        IOobject
        (
            "T",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info << "Reading field Q\n" << endl;
    volScalarField Q
    (
        IOobject
        (
            "Q",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("Q", dimMass/(dimLength*dimTime*dimTime*dimTime),0)
    );

    Info << "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info << "Creating field KappaEff\n" << endl;
    volScalarField KappaEff
    (
        IOobject
        (
            "KappaEff",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("KappaEff", dimLength*dimLength/dimTime,0)
    );

    Info << "Creating field Kappat\n" << endl;
    volScalarField Kappat
    (
        IOobject
        (
            "Kappat",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("Kappat", dimLength*dimLength/dimTime,0)
    );


    surfaceScalarField gradT
    (
        IOobject
        (
            "gradT",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("gradT", dimTemperature/dimLength,scalar(0))
    );


#   include "createPhi.H"

//    label pRefCell = 0;
//    scalar pRefValue = 0.0;
//    setRefCell(p, mesh.solutionDict().subDict("SIMPLE"), pRefCell, pRefValue);

    singlePhaseTransportModel laminarTransport(U, phi);

    autoPtr<incompressible::momentumTransportModel> turbulence
    (
        incompressible::momentumTransportModel::New(U, phi, laminarTransport)
    );

    //Correct boundaries only after all fields are loaded in
    T.correctBoundaryConditions();
