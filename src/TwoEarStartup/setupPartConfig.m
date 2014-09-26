function setupPartConfig( rrqXmlFileName )

[reposNeeded, subsNeeded, branchesNeeded, startupNeeded] = getPartRequirements( rrqXmlFileName );

for k = 1:length(reposNeeded)
    repoPath = readPathConfig( 'TwoEarsPaths.xml', reposNeeded{k} );
    if length(branchesNeeded{k})>0
        repoBranch = currentBranch( repoPath );
        if ~strcmp( repoBranch, branchesNeeded{k} )
            error( '"%s" needs to be checked out at "%s" branch, but current branch is "%s".', ...
                repoPath, branchesNeeded{k}, repoBranch );
        end
    end
    addpath( genpath( fullfile( repoPath, subsNeeded{k} ) ) );
    if ~isempty( startupNeeded{k} )
        startupFunc = str2func( startupNeeded{k} );
        startupFunc();
    end
end
