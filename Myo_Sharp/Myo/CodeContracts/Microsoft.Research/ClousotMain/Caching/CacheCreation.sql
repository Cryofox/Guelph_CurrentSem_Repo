﻿-- This file has been generated from CacheCreation.sqlce with CacheCreation.tt
-- Do not modify this file directly since it will be regenerated and your changes will be overwritten

CREATE TABLE Metadata (
  [Key] NVARCHAR(100) PRIMARY KEY,
  Value IMAGE NOT NULL);

CREATE TABLE Methods (
  Id BIGINT IDENTITY PRIMARY KEY,
  Hash BINARY(20) UNIQUE NOT NULL,
  Name NVARCHAR(4000) NOT NULL,
  PureParametersMask BIGINT NOT NULL,
  StatsTop INT NOT NULL,
  StatsBottom INT NOT NULL,
  StatsTrue INT NOT NULL,
  StatsFalse INT NOT NULL,
  SwallowedTop INT NOT NULL,
  SwallowedBottom INT NOT NULL,
  SwallowedTrue INT NOT NULL,
  SwallowedFalse INT NOT NULL,
  Contracts BIGINT NOT NULL,
  MethodInstructions BIGINT NOT NULL,
  ContractInstructions BIGINT NOT NULL,
  Timeout BIT NOT NULL,
  InferredExpr IMAGE, -- the BLOB with the serialized contract
  InferredExprHash BINARY(20), -- the hash of the "ToString()"
  InferredExprString NVARCHAR(4000)	-- Just the "ToString()", saved only in DEBUG mode
);

CREATE INDEX Hash ON Methods(Hash);

CREATE TABLE AssemblyBindings (
  AssemblyId UNIQUEIDENTIFIER NOT NULL,
  MethodId BIGINT NOT NULL CONSTRAINT FK_AssemblyBindings REFERENCES Methods(Id) ON DELETE CASCADE,
  PRIMARY KEY (AssemblyId, MethodId)
);

CREATE INDEX MethodId ON AssemblyBindings(MethodId);
CREATE INDEX AssemblyId ON AssemblyBindings(AssemblyId);

CREATE TABLE Outcomes (
  Id BIGINT IDENTITY PRIMARY KEY,
  MethodId BIGINT NOT NULL CONSTRAINT FK_Outcomes REFERENCES Methods(Id) ON DELETE CASCADE,
  Message NVARCHAR(4000) NOT NULL,
  Related BIT NOT NULL,
  ProofOutcome TINYINT NOT NULL,
  WarningType TINYINT NOT NULL,
  SubroutineLocalId INT NOT NULL,
  BlockIndex INT NOT NULL,
  ApcIndex INT NOT NULL
);

CREATE INDEX MethodId ON Outcomes(MethodId);

CREATE TABLE OutcomeContextEdges (
  Id BIGINT IDENTITY PRIMARY KEY,
  OutcomeId BIGINT NOT NULL CONSTRAINT FK_OutcomeContextEdges REFERENCES Outcomes(Id) ON DELETE CASCADE,
  Block1SubroutineLocalId INT NOT NULL,
  Block1Index INT NOT NULL,
  Block2SubroutineLocalId INT NOT NULL,
  Block2Index INT NOT NULL,
  Tag NVARCHAR(100) NOT NULL,
  Rank INT NOT NULL
);

CREATE INDEX OutcomeId ON OutcomeContextEdges(OutcomeId);

CREATE TABLE OutcomeContexts (
  Id BIGINT IDENTITY PRIMARY KEY,
  OutcomeId BIGINT NOT NULL CONSTRAINT FK_OutcomeContexts REFERENCES Outcomes(Id) ON DELETE CASCADE,
  Type TINYINT NOT NULL,
  AssociatedInfo INT NOT NULL
);

CREATE INDEX OutcomeId ON OutcomeContexts(OutcomeId);

CREATE TABLE Suggestions (
  Id BIGINT IDENTITY PRIMARY KEY,
  MethodId BIGINT NOT NULL CONSTRAINT FK_Suggestions REFERENCES Methods(Id) ON DELETE CASCADE,
  Kind NVARCHAR(100) NOT NULL,
  Message NVARCHAR(4000) NOT NULL,
  SubroutineLocalId INT NOT NULL,
  BlockIndex INT NOT NULL,
  ApcIndex INT NOT NULL
);

CREATE INDEX MethodId ON Suggestions(MethodId);

CREATE TABLE SuggestionContextEdges (
  Id BIGINT IDENTITY PRIMARY KEY,
  SuggestionId BIGINT NOT NULL CONSTRAINT FK_SuggestionContextEdges REFERENCES Suggestions(Id) ON DELETE CASCADE,
  Block1SubroutineLocalId INT NOT NULL,
  Block1Index INT NOT NULL,
  Block2SubroutineLocalId INT NOT NULL,
  Block2Index INT NOT NULL,
  Tag NVARCHAR(100) NOT NULL,
  Rank INT NOT NULL
);

CREATE INDEX SuggestionId ON SuggestionContextEdges(SuggestionId);

CREATE TABLE VersionResults (
  Version BIGINT PRIMARY KEY,
  Methods BIGINT NOT NULL,
  ContractInstructions BIGINT NOT NULL,
  Contracts BIGINT NOT NULL,
  MethodInstructions BIGINT NOT NULL,
  Outcomes BIGINT NOT NULL,
  StatsBottom BIGINT NOT NULL,
  StatsFalse BIGINT NOT NULL,
  StatsTop BIGINT NOT NULL,
  StatsTrue BIGINT NOT NULL,
  Suggestions BIGINT NOT NULL,
  SwallowedBottom BIGINT NOT NULL,
  SwallowedFalse BIGINT NOT NULL,
  SwallowedTop BIGINT NOT NULL,
  SwallowedTrue BIGINT NOT NULL,
  Timeout BIGINT NOT NULL,
  HasWarnings BIGINT NOT NULL,
  ZeroTop BIGINT NOT NULL
);

CREATE TABLE AssemblyInfo (
  AssemblyId UNIQUEIDENTIFIER PRIMARY KEY,
  Name NVARCHAR(400) NOT NULL,
  Created DATETIME NOT NULL,  
  IsBaseLine BIT,
  Version BIGINT
);
