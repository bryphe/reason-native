let projectDir =
  Filename.(
    Sys.executable_name
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> (dir => Filename.concat(dir, "src"))
    |> (dir => Filename.concat(dir, "chalk"))
  );

include TestRunner.Make({
  let config =
    TestRunner.TestFrameworkConfig.initialize({
      snapshotDir:
        Filename.(
          projectDir
          |> (dir => Filename.concat(dir, "test"))
          |> (dir => Filename.concat(dir, "lib"))
          |> (dir => Filename.concat(dir, "__snapshots__"))
        ),
      projectDir,
    });
});
