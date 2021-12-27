    // Thermal expansion coefficient [1/K]
    Info<< "\nReading Pr " << endl;
    dimensionedScalar Pr(laminarTransport.lookup("Pr"));
    Info<< "\nReading Prt " << endl;
    // Turbulent Prandtl number
    dimensionedScalar Prt(laminarTransport.lookup("Prt"));
    Info<< "\nReading Cp0 " << endl;
    // Heat capacity
    dimensionedScalar Cp0(laminarTransport.lookup("Cp0"));
    Info<< "\nReading rho0 " << endl;
    // Fluid density
    dimensionedScalar rho0(laminarTransport.lookup("rho0"));
