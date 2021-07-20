# Node Addons

This is a Node Addon Playground made by myself. I'll soon be making an article about it on my [blog](https://blog.lucaslemos.tech).

## Instructions

FIRST OF ALL, CHECK THE NODE-ADDON-API REPOSITORY (HERE)[https://github.com/nodejs/node-addon-api#examples]. It contains initial instructions about the setup and first running of node-gyp with your first addon.

To run all the addons you first need to clone the project and then run `npm install` or `yarn` (depending on the package manager you're using). Probably at the end of the node-gyp install process the addons will already be built, but if you don't see a `build` folder at the root folder of the project, follow this step: Run the `build` script with `npm run build` or `yarn build` to make node-gyp build the addons correctly.