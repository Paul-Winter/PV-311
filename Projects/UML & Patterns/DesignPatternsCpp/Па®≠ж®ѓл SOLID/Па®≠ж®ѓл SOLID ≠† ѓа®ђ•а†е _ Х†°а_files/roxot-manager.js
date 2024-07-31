(function (c) {
    if (isEngineInited()){
        return;
    }

    let script = document.createElement('script');
    script.type = 'text/javascript';
    script.async = 1;
    script.src = c.managerUrl;
    script.dataset.roxotInited = 'true';

    let head = document.getElementsByTagName('head')[0];
    head.insertBefore(script, head.firstChild);

    window.rom = window.rom || {cmd: [], icmd: []};
    window.rom.icmd = window.rom.icmd || [];
    window.rom.icmd.push(c);

    function isEngineInited(){
        return  document.querySelectorAll('[data-roxot-inited]').length;
    }
})({"publisherId":"c427193e-c45c-4b31-b9de-0d5bc41115fd","publisher":"TechMedia","adBlockMode":"iframe","iframeSspList":["google","prebid","prebid_dfp"],"managerUrl":"https:\/\/cdn.skcrtxr.com\/wrapper\/js\/common-engine.js?v=s-699ff0f0-1901-4ecd-8f53-942157a5651a","wrapperUrl":"https:\/\/cdn.skcrtxr.com\/wrapper\/js\/wrapper.js?v=s-699ff0f0-1901-4ecd-8f53-942157a5651a","placementConfigTemplate":"https:\/\/cdn.skcrtxr.com\/wrapper-builder\/placement\/__PLACEMENT_ID__?v=d-1699363398","gfsPlacementOptionsTemplate":"https:\/\/cdn.skcrtxr.com\/wrapper-builder\/gfs-placement\/__PLACEMENT_ID__?v=d-1699363398","isLanguageSpecific":true,"hostConfig":{"habr.com":{"wrapperOptions":[],"isAcceptableAdsEnabled":false}},"isBrowserSpecific":false,"isOsSpecific":false,"isDeviceTypeSpecific":false,"isGeoSpecific":false,"isGetParamSpecific":true,"dynamicUrlTemplate":"","wrapperConfig":{"uMeta":{"enabled":true},"syncThemes":{"enabled":true,"method":"chat_v2"},"monetizationStatsIntegration":{"enabled":true,"requestSettings":{"isNeedToSend":true,"sampleCoefficient":1},"impressionSettings":{"isNeedToSend":true,"sampleCoefficient":1},"visibleImpressionSettings":{"isNeedToSend":true,"sampleCoefficient":1},"urlSettings":{"isNeedToSend":true},"referrerSettings":{"isNeedToSend":true}},"host":"habr.com","engineFileName":"common-engine.js","enableAdFirstLoadInHiddenTab":true,"universalPlaceHolder":{"enabled":false},"prebid":{"prebidTimeout":1500,"adjustment":{"appnexus":0.95},"path":"https:\/\/cdn.skcrtxr.com\/wrapper\/js\/prebid.js?v=s-699ff0f0-1901-4ecd-8f53-942157a5651a"},"adfox":{"integrationTitle":"Adfox Monetizationsuperman","hb":{"timeout":1000,"biddersMap":{"betweenDigital":"1749489","myTarget":"1749495","otm":"1749502","segmento":"1749486","hybrid":"1749494","adriver":"1749497","buzzoola":"1749491","getintent":"1749562","videonow":"2349515","adfox_adsmart":"1935860","adfox_yandex_premium-publisher-network":"1952235","adfox_yandex_roxot-adfox-hb":"2293037"}}},"roxotYaMetric":{"enabled":true,"counterId":88477929},"syncCookies":{"enabled":true,"alwaysSyncBidders":["upravelBidder","mediaSniperBidder"]},"videojsLibs":{"path":"https:\/\/cdn.skcrtxr.com\/wrapper\/js\/video-libs.js?v=s-699ff0f0-1901-4ecd-8f53-942157a5651a"},"pageUrlVariableName":"roxotPlusPageUrl","stubVideoPath":"https:\/\/cdn.skcrtxr.com\/wrapper\/js\/video-ad?v=s-699ff0f0-1901-4ecd-8f53-942157a5651a","adfoxIntegrationType":"direct","yandexIntegrationType":"common","openRtbHost":"https:\/\/openrtb.skcrtxr.com"},"lazyLoading":[],"geoSpecificUrl":"https:\/\/geo-worker.skcrtxr.com\/api\/geo\/region","openRtbApiGetUserInfoUrl":"https:\/\/skcrtxr.com\/open-rtb-api\/get-user-bidders-info","syncCookiesUrl":"https:\/\/skcrtxr.com\/user-sync-api\/sync","monetizationStatsUrl":"https:\/\/worker.sttsmntz.ru\/stats\/format","umeUrl":"https:\/\/bidder.skcrtxr.com\/get-imp","umeCryptoUrl":"https:\/\/bidder.skcrtxr.com\/crypto\/get-imp"})